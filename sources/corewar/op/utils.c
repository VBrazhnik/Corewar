/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:33:19 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 17:33:31 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

int32_t	get_op_arg(t_vm **vm, t_cursor **cursor, t_op op, uint8_t index)
{
	int32_t		value;
	int32_t		addr;

	value = 0;
	if ((*cursor)->args_types[INDEX(index)] & T_REG)
	{
		value = (*cursor)->reg[INDEX(get_byte(vm, (*cursor)->pc,
														(*cursor)->step))];
		(*cursor)->step += REG_LEN;
	}
	else if ((*cursor)->args_types[INDEX(index)] & T_DIR)
	{
		value = bytecode_to_int32((*vm)->arena, (*cursor)->pc + (*cursor)->step, op.t_dir_size);
		(*cursor)->step += op.t_dir_size;
	}
	else if ((*cursor)->args_types[INDEX(index)] & T_IND)
	{
		addr = bytecode_to_int32((*vm)->arena,
									(*cursor)->pc + (*cursor)->step, IND_LEN);
		value = bytecode_to_int32((*vm)->arena,
									(*cursor)->pc + (addr % IDX_MOD), DIR_SIZE);
		(*cursor)->step += IND_LEN;
	}
	return (value);
}
