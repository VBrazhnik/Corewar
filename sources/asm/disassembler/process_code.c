/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:41:11 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/19 18:01:42 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_op.h"
#include "asm_disasm.h"
#include "ft_printf.h"

static size_t		get_size(t_statement *statement, unsigned i)
{
	if (statement->args_types[i] == T_REG)
		return (1);
	else if (statement->args_types[i] == T_IND)
		return (IND_SIZE);
	else
		return (statement->op->t_dir_size);
}

static void			process_arg(t_parser *parser,
								t_statement *statement,
								unsigned i)
{
	size_t size;

	size = get_size(statement, i);
	if (parser->code_size - parser->pos >= (int32_t)size)
	{
		statement->args[i] = bytecode_to_int32(&parser->code[parser->pos],
																		size);
		parser->pos += size;
		if (statement->args_types[i] == T_REG && statement->args[i] <= 0)
			register_error(parser);
	}
	else
		length_error(parser);
}

static void			process_args(t_parser *parser, t_statement *statement)
{
	unsigned i;

	i = 0;
	while (i < statement->op->args_num)
	{
		process_arg(parser, statement, i);
		i++;
	}
}

static t_statement	*process_statement(t_parser *parser)
{
	t_statement	*statement;
	uint8_t		op_code;

	statement = init_statement();
	op_code = parser->code[parser->pos];
	if (op_code >= 0x01 && op_code <= 0x10)
	{
		parser->pos++;
		statement->op = &g_op[INDEX(op_code)];
		if (statement->op->args_types_code && parser->pos >= parser->code_size)
			length_error(parser);
		process_arg_types(parser, statement);
		if (is_arg_types_valid(statement))
		{
			if (statement->op->args_types_code)
				parser->pos++;
			process_args(parser, statement);
		}
		else
			arg_types_code_error(parser);
	}
	else
		op_code_error(parser);
	return (statement);
}

void				process_exec_code(t_parser *parser)
{
	while (parser->pos < parser->code_size)
		add_statement(&(parser->statements), process_statement(parser));
}
