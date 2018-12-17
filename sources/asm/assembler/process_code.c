/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:00:12 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"

static void		process_label(t_parser *parser, t_token **current)
{
	t_label	*label;
	char	*name;

	if (!(name = ft_strsub((*current)->content,
				0, ft_strlen((*current)->content) - 1)))
		terminate(ERR_STR_INIT);
	if (!(label = find_label(parser->labels, name)))
		add_label(&(parser->labels), init_label(name, parser->op_pos));
	if (label && label->op_pos == -1)
		label->op_pos = parser->pos;
	ft_strdel(&name);
}

static int8_t	process_args(t_parser *parser, t_token **current, t_op *op)
{
	int		arg_num;
	int8_t	types_code;
	int8_t	type;

	arg_num = 0;
	types_code = 0;
	while (arg_num < op->args_num)
	{
		if ((*current)->type >= REGISTER && (*current)->type <= INDIRECT_LABEL)
		{
			type = process_arg(parser, current, op, arg_num);
			update_types_code(&types_code, type, arg_num);
			(*current) = (*current)->next;
		}
		else
			token_error((*current));
		if (arg_num++ != op->args_num - 1)
		{
			if ((*current)->type != SEPARATOR)
				token_error((*current));
			(*current) = (*current)->next;
		}
	}
	return (types_code);
}

static void		process_operator(t_parser *parser, t_token **current)
{
	t_op	*op;
	int8_t	types_code;

	if ((op = get_op((*current)->content)))
	{
		parser->code[parser->pos++] = op->code;
		(*current) = (*current)->next;
		if (op->args_types_code)
			parser->pos++;
		types_code = process_args(parser, current, op);
		if (op->args_types_code)
			parser->code[parser->op_pos + 1] = types_code;
	}
	else
		operator_error((*current));
}

void			process_asm_code(t_parser *parser, t_token **current)
{
	while ((*current)->type != END)
	{
		if (parser->pos >= parser->code_size)
			update_code_buff(parser);
		parser->op_pos = parser->pos;
		if ((*current)->type == LABEL)
		{
			process_label(parser, current);
			(*current) = (*current)->next;
		}
		if ((*current)->type == OPERATOR)
			process_operator(parser, current);
		if ((*current)->type == NEW_LINE)
			(*current) = (*current)->next;
		else
			token_error((*current));
	}
}
