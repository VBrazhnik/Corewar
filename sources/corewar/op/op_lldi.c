/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:49:45 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 13:04:50 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_lldi(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		arg1;
	int32_t		arg2;
	int32_t		arg3;
	int32_t		value;

	(*cursor)->step += OP_CODE_LEN + ARGS_CODE_LEN;
	arg1 = get_op_arg(vm, cursor, op, 1);
	arg2 = get_op_arg(vm, cursor, op, 2);
	arg3 = get_byte(vm, (*cursor)->pc, (*cursor)->step);
	value = bytecode_to_int32((*vm)->arena,
									((*cursor)->pc + (arg1 + arg2)), DIR_SIZE);
	if (value == 0)
		(*cursor)->carry = true;
	else
		(*cursor)->carry = false;
	(*cursor)->reg[INDEX(arg3)] = value;
	(*cursor)->step += REG_LEN;
}
