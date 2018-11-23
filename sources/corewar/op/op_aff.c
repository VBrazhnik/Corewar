/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:59:33 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 12:47:12 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void			op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t		value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, true);
	if (vm->display_aff)
		printf("Aff: %c\n", (char)value);
	cursor->step += REG_LEN;
}
