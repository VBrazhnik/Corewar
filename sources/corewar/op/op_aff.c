/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:59:33 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/15 11:23:55 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

void			op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (vm->display_aff)
		printf("Aff: %c\n", (char)value);
	if (vm->vs)
	{
		vm->vs->aff_symbol = (char)value;
		if (cursor->reg[INDEX(1)] >= 1 && cursor->reg[INDEX(1)] <= 4)
			vm->vs->aff_owner = FT_ABS(cursor->reg[INDEX(1)]);
		else
			vm->vs->aff_owner = vm->vs->map[cursor->pc].value;
		vm->vs->map[cursor->pc].value = COLOR_YELLOW;
		vm->vs->map[cursor->pc].time_to_wait = CYCLE_TO_WAIT;
	}
}
