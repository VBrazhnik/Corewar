/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:32:58 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 18:12:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

t_bool			is_arg_types_valid(t_cursor *cursor, t_op *op)
{
	int32_t i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (false);
		i++;
	}
	return (true);
}

static t_bool	is_register(t_vm *vm, int32_t pc, int32_t step)
{
	int8_t r_id;

	r_id = get_byte(vm, pc, step);
	return (t_bool)(r_id >= 1 && r_id <= REG_NUMBER);
}

t_bool			is_args_valid(t_cursor *cursor, t_vm *vm, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0));
	while (i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG)
			&& !is_register(vm, cursor->pc, step))
			return (false);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (true);
}
