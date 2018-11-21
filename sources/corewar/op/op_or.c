/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:58:42 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 15:08:10 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_or(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		value;
	int32_t		reg;

	(*cursor)->step += OP_CODE_LEN + ARGS_CODE_LEN;
	arg_1 = get_op_arg(vm, cursor, op, 1);
	arg_2 = get_op_arg(vm, cursor, op, 2);
	value = arg_1 | arg_2;
	(*cursor)->carry = (t_bool)(!value);
	reg = get_byte(vm, (*cursor)->pc, (*cursor)->step);
	(*cursor)->reg[INDEX(reg)] = value;
	(*cursor)->step += REG_LEN;
}
