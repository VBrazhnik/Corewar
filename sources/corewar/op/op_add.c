/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:50:27 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 15:37:46 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	op_add(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		value_1;
	int32_t		value_2;
	int32_t		reg;
	int32_t		value;

	(*cursor)->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value_1 = get_op_arg(vm, cursor, op, 1);
	value_2 = get_op_arg(vm, cursor, op, 2);
	value = value_1 + value_2;
	(*cursor)->carry = (t_bool)(!value);
	reg = get_byte(vm, (*cursor)->pc, (*cursor)->step);
	(*cursor)->reg[INDEX(reg)] = value;
	(*cursor)->step += REG_LEN;
}
