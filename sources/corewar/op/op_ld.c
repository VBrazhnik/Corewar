/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:29:52 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 12:17:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	op_ld(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t		value;

	(*cursor)->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, op, 1);
	(*cursor)->carry = (t_bool)(!value);
	(*cursor)->reg[INDEX(get_byte(vm, (*cursor)->pc, (*cursor)->step))] = value;
	(*cursor)->step += REG_LEN;
}
