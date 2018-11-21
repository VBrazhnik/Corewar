/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:28:48 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 17:44:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_sti(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		value;
	int32_t		addr_1;
	int32_t		addr_2;

	(*cursor)->step += OP_CODE_LEN + ARGS_CODE_LEN;
	value = get_op_arg(vm, cursor, op, 1);
	addr_1 = get_op_arg(vm, cursor, op, 2);
	addr_2 = get_op_arg(vm, cursor, op, 3);
	int32_to_bytecode((*vm)->arena,
			((*cursor)->pc + ((addr_1 + addr_2) % IDX_MOD)), value, DIR_SIZE);
}
