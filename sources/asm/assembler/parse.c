/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 00:56:00 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"
#include "ft_printf.h"

void	parse_symbols(t_parser *parser,
					char *line,
					unsigned start,
					t_token *token)
{
	unsigned	column;

	column = parser->column;
	while (line[parser->column]
		&& ft_strchr(LABEL_CHARS, line[parser->column]))
		parser->column++;
	if ((parser->column - column) && line[parser->column] == LABEL_CHAR
		&& ++parser->column)
	{
		token->content = get_token_content(parser, line, start);
		token->type = LABEL;
		add_token(&parser->tokens, token);
	}
	else if ((parser->column - column) && is_delimiter(line[parser->column]))
	{
		token->content = get_token_content(parser, line, start);
		if (token->type == INDIRECT)
			token->type = (is_register(token->content)) ? REGISTER : OPERATOR;
		add_token(&parser->tokens, token);
	}
	else
		lexical_error(parser);
}

void	parse_num(t_parser *parser,
					char *line,
					unsigned start,
					t_token *token)
{
	unsigned	column;

	if (line[parser->column] == '-')
		parser->column++;
	column = parser->column;
	while (ft_isdigit(line[parser->column]))
		parser->column++;
	if (parser->column - column)
	{
		if (token->type == DIRECT || is_delimiter(line[parser->column]))
		{
			token->content = get_token_content(parser, line, start);
			add_token(&parser->tokens, token);
		}
	}
	else if (token->type != DIRECT)
	{
		parser->column = start;
		parse_symbols(parser, line, start, token);
	}
	else
		lexical_error(parser);
}

void	parse_str(t_parser *parser,
					char **line,
					unsigned start,
					t_token *token)
{
	char	*begin;
	char	*end;
	ssize_t	size;
	char	*str;
	char	*tmp;

	size = 1;
	while ((begin = ft_strchr(&((*line)[start]), '\"'))
		&& (end = ft_strrchr(&((*line)[start]), '\"'))
		&& begin == end && (size = get_row(parser->fd, &str)) > 0)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(*line, str)))
			terminate(ERR_STR_INIT);
		ft_strdel(&tmp);
		ft_strdel(&str);
	}
	update_parser_position(parser, *line);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size == 0)
		lexical_error(parser);
	token->content = get_token_content(parser, *line, start);
	add_token(&parser->tokens, token);
}

void	parse_token(t_parser *parser, char **line)
{
	if (*(*line + parser->column) == SEPARATOR_CHAR && ++parser->column)
		add_token(&parser->tokens, init_token(parser, SEPARATOR));
	else if (*(*line + parser->column) == '\n' && ++parser->column)
		add_token(&parser->tokens, init_token(parser, NEW_LINE));
	else if (*(*line + parser->column) == '.')
		parse_symbols(parser, *line,
				parser->column++, init_token(parser, COMMAND));
	else if (*(*line + parser->column) == DIRECT_CHAR && ++parser->column)
	{
		if (*(*line + parser->column) == LABEL_CHAR && ++parser->column)
			parse_symbols(parser, *line,
					parser->column - 2, init_token(parser, DIRECT_LABEL));
		else
			parse_num(parser, *line,
					parser->column - 1, init_token(parser, DIRECT));
	}
	else if (*(*line + parser->column) == '\"')
		parse_str(parser, line, parser->column, init_token(parser, STRING));
	else if (*(*line + parser->column) == LABEL_CHAR)
		parse_symbols(parser, *line,
				parser->column++, init_token(parser, INDIRECT_LABEL));
	else
		parse_num(parser, *line, parser->column, init_token(parser, INDIRECT));
}

void	parse_asm(t_parser *parser)
{
	ssize_t	size;
	char	*line;

	while ((size = get_row(parser->fd, &line)) > 0 && ++parser->row)
	{
		parser->column = 0;
		while (line[parser->column])
		{
			skip_whitespaces(parser, line);
			skip_comment(parser, line);
			if (line[parser->column])
				parse_token(parser, &line);
		}
		ft_strdel(&line);
	}
	if (size == -1)
		terminate(ERR_READ_FILE);
	add_token(&(parser->tokens), init_token(parser, END));
}
