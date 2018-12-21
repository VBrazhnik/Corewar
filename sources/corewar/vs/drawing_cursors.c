/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_cursors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:09:31 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 22:33:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void	clear_cursor(t_vm *vm, t_cursor *cursor)
{
	if (vm->vs->map[cursor->pc].value >= INDEX_CURSOR(MIN_PLAYER_ID)
	&& vm->vs->map[cursor->pc].value <= INDEX_CURSOR(MAX_PLAYER_ID))
		vm->vs->map[cursor->pc].value =
				INDEX_PLAYER(vm->vs->map[cursor->pc].value);
	else if (vm->vs->map[cursor->pc].value == ZERO_CURSOR)
		vm->vs->map[cursor->pc].value = 0;
}

void	draw_cursor(t_vm *vm, t_cursor *cursor)
{
	if (vm->vs->map[cursor->pc].value >= MIN_PLAYER_ID
	&& vm->vs->map[cursor->pc].value <= MAX_PLAYER_ID)
		vm->vs->map[cursor->pc].value =
				INDEX_CURSOR(vm->vs->map[cursor->pc].value);
	else if (ZERO_BYTE_CURSOR(vm->vs->map[cursor->pc].value))
		vm->vs->map[cursor->pc].value =
				ZERO_BYTE_CURSOR(vm->vs->map[cursor->pc].value);
}
