/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:32:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 17:36:52 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

static void	set_arg_type(int8_t arg_type, int8_t index, t_cursor *cursor)
{
	cursor->args_types[INDEX(index)] = g_arg_code[INDEX(arg_type)];
}

void		parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte(vm, cursor->pc, 1);
		if (op->args_num >= 1)
			set_arg_type((int8_t)((args_types_code & 0xC0) >> 6), 1, cursor);
		if (op->args_num >= 2)
			set_arg_type((int8_t)((args_types_code & 0x30) >> 4), 2, cursor);
		if (op->args_num >= 3)
			set_arg_type((int8_t)((args_types_code & 0xC) >> 2), 3, cursor);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}
