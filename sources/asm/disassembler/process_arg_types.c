/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:39:40 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 11:15:17 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"
#include "ft_printf.h"

static uint8_t	get_arg_type(int8_t code)
{
	if (code == DIR_CODE)
		return (T_DIR);
	else if (code == REG_CODE)
		return (T_REG);
	else if (code == IND_CODE)
		return (T_IND);
	else
		return (0);
}

static void		set_arg_type(int8_t arg_code,
								int8_t index,
								t_statement *statement)
{
	statement->args_types[INDEX(index)] = get_arg_type(arg_code);
}

void			process_arg_types(t_parser *parser, t_statement *statement)
{
	int8_t args_types_code;

	if (statement->op->args_types_code)
	{
		args_types_code = parser->code[parser->pos];
		if (statement->op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, statement);
		if (statement->op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, statement);
		if (statement->op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, statement);
		validate_types_code(parser, args_types_code, statement->op->args_num);
	}
	else
		statement->args_types[0] = statement->op->args_types[0];
}
