/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_cursors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:09:31 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 17:42:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	clear_cursor(t_vm *vm, t_cursor *cursor)
{
	if (vm->vs->map[cursor->pc].index >= INDEX_CURSOR(0)
		&& vm->vs->map[cursor->pc].index <= INDEX_CURSOR(MAX_PLAYER_ID))
		vm->vs->map[cursor->pc].index =
				INDEX_PLAYER(vm->vs->map[cursor->pc].index);
}

void	draw_cursor(t_vm *vm, t_cursor *cursor)
{
	if (vm->vs->map[cursor->pc].index >= 0
		&& vm->vs->map[cursor->pc].index <= MAX_PLAYER_ID)
		vm->vs->map[cursor->pc].index =
				INDEX_CURSOR(vm->vs->map[cursor->pc].index);
}
