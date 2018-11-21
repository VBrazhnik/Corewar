/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:33:56 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 17:24:55 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_ldi(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		addr_1;
	int32_t		addr_2;
	int32_t		reg;

	(*cursor)->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, op, 1);
	addr_2 = get_op_arg(vm, cursor, op, 2);
	reg = get_byte(vm, (*cursor)->pc, (*cursor)->step);
	(*cursor)->reg[INDEX(reg)] = bytecode_to_int32((*vm)->arena,
				((*cursor)->pc + ((addr_1 + addr_2) % IDX_MOD)), DIR_SIZE);
	(*cursor)->step += REG_LEN;
}
