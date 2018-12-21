/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:23:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/21 21:17:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void	sound_player_status(t_vm *vm)
{
	vm->vs->curr_cursor_position = HEIGHT - 5;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Sounds are turned ");
	if (vm->vs->sounds)
		wprintw(vm->vs->win_info, "ON ");
	else
		wprintw(vm->vs->win_info, "OFF");
}

void	play_winner(t_vm *vm)
{
	if (vm->cursors_num - vm->vs->cariage_quant_delta)
		system("pkill afplay");
	system("afplay music/winner.mp3 &> /dev/null &");
}

void	play_sounds(t_vm *vm)
{
	if (vm->vs->sounds)
	{
		if (vm->cursors_num - vm->vs->cariage_quant_delta)
			system("afplay music/blaster_sound.mp3 &> /dev/null &");
	}
}
