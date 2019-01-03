/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:26:52 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/01/03 06:45:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	draw_exec_status(t_vm *vm)
{
	vm->vs->cursor_pos = 2;
	if (vm->vs->is_running)
	{
		wattron(vm->vs->win_info, COLOR_PAIR(GREEN));
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos,
				DEFAULT_INDENT,
				"%-10s", "RUNNING");
		wattroff(vm->vs->win_info, COLOR_PAIR(GREEN));
	}
	else
	{
		wattron(vm->vs->win_info, COLOR_PAIR(RED));
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos,
				DEFAULT_INDENT,
				"%-10s", (vm->cursors_num) ? "PAUSED" : "STOPPED");
		wattroff(vm->vs->win_info, COLOR_PAIR(RED));
	}
}

void	draw_sounds_status(t_vm *vm)
{
	vm->vs->cursor_pos = HEIGHT - 5;
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos,
			DEFAULT_INDENT,
			"Sounds are ");
	wprintw(vm->vs->win_info, "%-3s", (vm->vs->sounds) ? "ON" : "OFF");
}

void	draw_help_status(t_vm *vm)
{
	vm->vs->cursor_pos = HEIGHT - 3;
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos,
			DEFAULT_INDENT,
			"Press 'H' to %s help",
			(vm->vs->display_help) ? "hide" : "show");
	if (!vm->vs->display_help)
	{
		delwin(vm->vs->win_help);
		vm->vs->win_help = newwin(HEIGHT / 5, WIDTH, HEIGHT + 2, 2);
	}
	else
		draw_help(vm);
}
