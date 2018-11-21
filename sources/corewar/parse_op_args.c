/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 22:26:47 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/10 21:41:07 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void		parse_arg_type(uint8_t arg_type, uint8_t index, t_cursor **cursor)
{
	(*cursor)->args_types[INDEX(index)] = g_arg_code[INDEX(arg_type)];
}

void		parse_arg_types(t_vm **vm, t_cursor **cursor)
{
	t_op		op;
	int8_t		args_types;

	if (((*cursor)->op_code > 0 && (*cursor)->op_code <= 0x10))
	{
		op = g_op[INDEX((*cursor)->op_code)];
		if (op.args_types_code)
		{
			args_types = get_byte(vm, (*cursor)->pc, 1);
			if (op.args_num >= 1)
				parse_arg_type((args_types & 0xC0) >> 6, 1, cursor);
			if (op.args_num >= 2)
				parse_arg_type((args_types & 0x30) >> 4, 2, cursor);
			if (op.args_num >= 3)
				parse_arg_type((args_types & 0xC) >> 2, 3, cursor);
		}
		else
			(*cursor)->args_types[0] = op.args_types[0];
	}
}

t_bool		validate_arg_types(t_cursor **cursor)
{
	int32_t	i;

	i = 0;
	if (((*cursor)->op_code > 0 && (*cursor)->op_code <= 0x10))
	{
		while (i < g_op[INDEX((*cursor)->op_code)].args_num)
		{
			if (!((*cursor)->args_types[i]
					& g_op[INDEX((*cursor)->op_code)].args_types[i]))
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

uint32_t	step_size(uint8_t arg_type, t_op op)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (op.t_dir_size);
	else if (arg_type & T_IND)
		return (IND_LEN);
	return (0);
}

uint32_t	calc_step(t_cursor **cursor)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = 0;
	if (((*cursor)->op_code > 0 && (*cursor)->op_code <= 0x10))
	{
		while (i < g_op[INDEX((*cursor)->op_code)].args_num)
		{
			step += step_size((*cursor)->args_types[i],
							g_op[INDEX((*cursor)->op_code)]);
			i++;
		}
	}
	return (step);
}

t_bool		is_reg_valid(t_vm **vm, int32_t pc, int32_t step)
{
	int8_t reg;

	reg = get_byte(vm, pc, step);
	return (t_bool)(reg >= 1 && reg <= REG_NUMBER);
}

t_bool		validate_args(t_cursor **cursor, t_vm **vm)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (OP_CODE_LEN + ((g_op[INDEX((*cursor)->op_code)].args_types_code) ?
		(ARGS_CODE_LEN) : (0)));
	if (((*cursor)->op_code > 0 && (*cursor)->op_code <= 0x10))
	{
		while (i < g_op[INDEX((*cursor)->op_code)].args_num)
		{
			if (((*cursor)->args_types[i] == T_REG) && !is_reg_valid(vm, (*cursor)->pc, step))
				return (false);
			step += step_size((*cursor)->args_types[i],
				g_op[INDEX((*cursor)->op_code)]);
			i++;
		}
		return (true);
	}
	return (false);
}
