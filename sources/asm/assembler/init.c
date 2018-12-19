/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:11:01 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/19 16:12:30 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"

t_parser	*init_asm_parser(int fd)
{
	t_parser	*parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		terminate(ERR_PARSER_INIT);
	parser->fd = fd;
	parser->row = 0;
	parser->column = 0;
	parser->pos = 0;
	parser->op_pos = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code = NULL;
	parser->code_size = 0;
	parser->labels = NULL;
	return (parser);
}

t_label		*init_label(char *name, int op_pos)
{
	t_label	*label;

	if (!(label = (t_label *)ft_memalloc(sizeof(t_label))))
		terminate(ERR_LABEL_INIT);
	if (!(label->name = ft_strdup(name)))
		terminate(ERR_STR_INIT);
	label->op_pos = op_pos;
	label->mentions = NULL;
	label->next = NULL;
	return (label);
}

t_mention	*init_mention(t_parser *parser, t_token *token, size_t size)
{
	t_mention	*mention;

	if (!(mention = (t_mention *)ft_memalloc(sizeof(t_mention))))
		terminate(ERR_MENTION_INIT);
	mention->row = token->row;
	mention->column = token->column;
	mention->pos = parser->pos;
	mention->op_pos = parser->op_pos;
	mention->size = size;
	mention->next = NULL;
	return (mention);
}

t_token		*init_token(t_parser *parser, t_type type)
{
	t_token	*token;

	if (!(token = (t_token *)ft_memalloc(sizeof(t_token))))
		terminate(ERR_TOKEN_INIT);
	token->content = NULL;
	token->type = type;
	token->row = parser->row;
	if (type == SEPARATOR || type == NEW_LINE)
		token->column = parser->column - 1;
	else
		token->column = parser->column;
	token->next = NULL;
	return (token);
}
