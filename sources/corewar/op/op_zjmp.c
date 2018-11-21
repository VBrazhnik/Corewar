/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:17:29 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 15:14:20 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_zjmp(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		pos;

	(*cursor)->step += OP_CODE_LEN;
	pos = get_op_arg(vm, cursor, op, 1);
	if ((*cursor)->carry)
	{
		(*cursor)->pc = calc_addr((*cursor)->pc + (pos % IDX_MOD));
		(*cursor)->step = 0;
	}
}
