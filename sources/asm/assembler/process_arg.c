/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:11:14 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/20 21:00:47 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"

static int8_t	get_arg_type(t_type type)
{
	if (type == DIRECT || type == DIRECT_LABEL)
		return (T_DIR);
	else if (type == INDIRECT || type == INDIRECT_LABEL)
		return (T_IND);
	else if (type == REGISTER)
		return (T_REG);
	else
		return (0);
}

static void		process_mention(t_parser *parser, t_token *current, t_op *op)
{
	t_label		*label;
	char		*name;
	unsigned	start;
	size_t		size;

	start = (current->type == DIRECT_LABEL) ? 2 : 1;
	size = (current->type == DIRECT_LABEL) ? op->t_dir_size : IND_SIZE;
	if (!(name = ft_strsub(current->content,
				start, ft_strlen(current->content) - start)))
		terminate(ERR_STR_INIT);
	if (!(label = find_label(parser->labels, name)))
	{
		label = init_label(name, -1);
		add_label(&(parser->labels), label);
	}
	ft_strdel(&name);
	add_mention(&label->mentions, init_mention(parser, current, size));
	parser->pos += size;
}

static void		process_num(t_parser *parser, t_token *current, t_op *op)
{
	unsigned	start;
	size_t		size;

	start = (current->type == DIRECT) ? 1 : 0;
	size = (current->type == DIRECT) ? op->t_dir_size : IND_SIZE;
	if (size == 2)
		int32_to_bytecode(parser->code,
						parser->pos,
						(int16_t)ft_atoi32(&current->content[start]),
						size);
	else
		int32_to_bytecode(parser->code,
						parser->pos,
						ft_atoi32(&current->content[start]),
						size);
	parser->pos += size;
}

static void		process_register(t_parser *parser, t_token *current)
{
	int32_to_bytecode(parser->code,
						parser->pos,
						(int8_t)ft_atoi(&current->content[1]),
						1);
	parser->pos += 1;
}

int8_t			process_arg(t_parser *parser,
							t_token **current,
							t_op *op,
							int arg_num)
{
	int8_t	type;

	type = get_arg_type((*current)->type);
	if (!(op->args_types[arg_num] & type))
		arg_type_error(op, arg_num, *current);
	if ((*current)->type == INDIRECT_LABEL
		|| (*current)->type == DIRECT_LABEL)
		process_mention(parser, *current, op);
	else if ((*current)->type == INDIRECT
		|| (*current)->type == DIRECT)
		process_num(parser, *current, op);
	else
		process_register(parser, *current);
	return (type);
}
