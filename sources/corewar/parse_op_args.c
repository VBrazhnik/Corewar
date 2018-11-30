/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 22:26:47 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/29 20:09:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void		parse_arg_type(uint8_t arg_type, uint8_t index, t_cursor *cursor)
{
	cursor->args_types[INDEX(index)] = g_arg_code[INDEX(arg_type)];
}

void		parse_arg_types(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t		args_types;

	if (op->args_types_code)
	{
		args_types = get_byte(vm, cursor->pc, 1);
		if (op->args_num >= 1)
			parse_arg_type((uint8_t)((args_types & 0xC0) >> 6), 1, cursor);
		if (op->args_num >= 2)
			parse_arg_type((uint8_t)((args_types & 0x30) >> 4), 2, cursor);
		if (op->args_num >= 3)
			parse_arg_type((uint8_t)((args_types & 0xC) >> 2), 3, cursor);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

t_bool		valid_arg_types(t_cursor *cursor, t_op *op)
{
	int32_t	i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool		is_reg(t_vm *vm, int32_t pc, int32_t step)
{
	int8_t reg;

	reg = get_byte(vm, pc, step);
	return (t_bool)(reg >= 1 && reg <= REG_NUMBER);
}

t_bool		valid_args(t_cursor *cursor, t_vm *vm, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0));
	while (i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG) && !is_reg(vm, cursor->pc, step))
			return (false);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (true);
}
