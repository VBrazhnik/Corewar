/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:31:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/09 22:52:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	op_st(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		reg_value;
	int32_t		addr;

	(void)op;
	(*cursor)->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg_value = get_op_arg(vm, cursor, op, 1);
	if ((*cursor)->args_types[1] == T_REG)
	{
		(*cursor)->reg[INDEX(get_byte(vm, (*cursor)->pc,
											(*cursor)->step))] = reg_value;
		(*cursor)->step += REG_LEN;
	}
	else if ((*cursor)->args_types[1] == T_IND)
	{
		addr = bytecode_to_int32((*vm)->arena,
								(*cursor)->pc + (*cursor)->step, IND_SIZE);
		int32_to_bytecode((*vm)->arena,
					(*cursor)->pc + (addr % IDX_MOD), reg_value, DIR_SIZE);
		(*cursor)->step += IND_SIZE;
	}
}
