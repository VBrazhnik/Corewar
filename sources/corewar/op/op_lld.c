/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:46:46 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 11:48:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_lld(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		value;
	int32_t		address;

	(*cursor)->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	if ((*cursor)->args_types[0] == T_DIR)
		value = get_op_arg(vm, cursor, op, 1);
	else
	{
		address = bytecode_to_int32((*vm)->arena,
								(*cursor)->pc + (*cursor)->step, IND_SIZE);
		value = bytecode_to_int32((*vm)->arena,
								(*cursor)->pc + address, op.t_dir_size);
		(*cursor)->step += IND_SIZE;
	}
	if (value == 0)
		(*cursor)->carry = true;
	else
		(*cursor)->carry = false;
	(*cursor)->reg[INDEX(get_byte(vm,
								(*cursor)->pc, (*cursor)->step))] = value;
	(*cursor)->step += REG_LEN;
}
