/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:54:46 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 16:16:23 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_lfork(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		pos;
	t_cursor	*temp_elem;

	(*cursor)->step += OP_CODE_LEN;
	pos = get_op_arg(vm, cursor, op, 1);
	temp_elem = init_cursor((*cursor)->reg[0],
		calc_addr(pos + (*cursor)->pc), (*vm)->arena[(*cursor)->pc + pos],
		g_op[INDEX((*vm)->arena[(*cursor)->pc + pos])].cycles);
	copy_reg((*cursor), temp_elem);
	(*vm)->cursors_num++;
	temp_elem->carry = (*cursor)->carry;
	temp_elem->next = (*vm)->cursors;
	(*vm)->cursors = temp_elem;
}
