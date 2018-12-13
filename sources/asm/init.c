/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:11:01 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 04:23:05 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_error_msg.h"

t_parser	*init_parser(int fd)
{
	t_parser	*parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		terminate(ERR_ASM_INIT);
	parser->fd = fd;
	parser->line = 0;
	parser->column = 0;
	parser->pos = 0;
	parser->op_pos = 0;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code = NULL;
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

t_mention	*init_mention(t_parser *parser, size_t size)
{
	t_mention	*mention;

	if (!(mention = (t_mention *)ft_memalloc(sizeof(t_mention))))
		terminate(ERR_MENTION_INIT);
	mention->line = parser->line;
	mention->column = parser->column;
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
		terminate(ERR_INIT_TOKEN);
	token->content = NULL;
	token->type = type;
	token->line = parser->line;
	token->column = parser->column;
	token->next = NULL;
	return (token);
}
