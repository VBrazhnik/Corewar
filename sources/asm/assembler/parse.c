/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 00:56:00 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/19 22:06:51 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"
#include "ft_printf.h"

void	parse_symbols(t_parser *parser,
					char *row,
					unsigned start,
					t_token *token)
{
	unsigned column;

	token->column = start;
	column = parser->column;
	while (row[parser->column]
		&& ft_strchr(LABEL_CHARS, row[parser->column]))
		parser->column++;
	if ((parser->column - column) && row[parser->column] == LABEL_CHAR
		&& ++parser->column)
	{
		token->content = get_token_content(parser, row, start);
		token->type = LABEL;
		add_token(&parser->tokens, token);
	}
	else if ((parser->column - column) && is_delimiter(row[parser->column]))
	{
		token->content = get_token_content(parser, row, start);
		if (token->type == INDIRECT)
			token->type = (is_register(token->content)) ? REGISTER : OPERATOR;
		add_token(&parser->tokens, token);
	}
	else
		lexical_error(parser);
}

void	parse_num(t_parser *parser,
					char *row,
					unsigned start,
					t_token *token)
{
	unsigned column;

	token->column = start;
	if (row[parser->column] == '-')
		parser->column++;
	column = parser->column;
	while (ft_isdigit(row[parser->column]))
		parser->column++;
	if ((parser->column - column)
		&& (token->type == DIRECT || is_delimiter(row[parser->column])))
	{
		token->content = get_token_content(parser, row, start);
		add_token(&parser->tokens, token);
	}
	else if (token->type != DIRECT)
	{
		parser->column = start;
		parse_symbols(parser, row, start, token);
	}
	else
		lexical_error(parser);
}

void	parse_str(t_parser *parser,
					char **row,
					unsigned start,
					t_token *token)
{
	char	*end;
	ssize_t	size;
	char	*str;

	token->column = start;
	size = 1;
	while (!(end = ft_strchr(&((*row)[start + 1]), '\"'))
		&& (size = get_row(parser->fd, &str)) > 0)
		*row = join_str(row, &str);
	update_parser_position(parser, *row);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size == 0)
		lexical_error(parser);
	if (!(token->content = ft_strsub(*row, start, end + 1 - &((*row)[start]))))
		terminate(ERR_STR_INIT);
	if (end - parser->column != *row)
		update_row(row, end - parser->column);
	parser->column++;
	add_token(&parser->tokens, token);
}

void	parse_token(t_parser *parser, char **row)
{
	if (*(*row + parser->column) == SEPARATOR_CHAR && ++parser->column)
		add_token(&parser->tokens, init_token(parser, SEPARATOR));
	else if (*(*row + parser->column) == '\n' && ++parser->column)
		add_token(&parser->tokens, init_token(parser, NEW_LINE));
	else if (*(*row + parser->column) == '.')
		parse_symbols(parser, *row, parser->column++,
					init_token(parser, COMMAND));
	else if (*(*row + parser->column) == DIRECT_CHAR && ++parser->column)
	{
		if (*(*row + parser->column) == LABEL_CHAR && ++parser->column)
			parse_symbols(parser, *row, parser->column - 2,
					init_token(parser, DIRECT_LABEL));
		else
			parse_num(parser, *row, parser->column - 1,
					init_token(parser, DIRECT));
	}
	else if (*(*row + parser->column) == '\"')
		parse_str(parser, row, parser->column, init_token(parser, STRING));
	else if (*(*row + parser->column) == LABEL_CHAR)
		parse_symbols(parser, *row, parser->column++,
					init_token(parser, INDIRECT_LABEL));
	else
		parse_num(parser, *row, parser->column, init_token(parser, INDIRECT));
}

void	parse_asm(t_parser *parser)
{
	ssize_t	size;
	char	*row;

	while (++parser->row
		&& !(parser->column = 0)
		&& (size = get_row(parser->fd, &row)) > 0)
	{
		while (row[parser->column])
		{
			skip_whitespaces(parser, row);
			skip_comment(parser, row);
			if (row[parser->column])
				parse_token(parser, &row);
		}
		ft_strdel(&row);
	}
	if (size == -1)
		terminate(ERR_READ_FILE);
	add_token(&(parser->tokens), init_token(parser, END));
}
