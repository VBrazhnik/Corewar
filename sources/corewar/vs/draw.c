/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:39:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 23:17:15 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void	draw_border(WINDOW *wnd)
{
	wattron(wnd, COLOR_PAIR(GRAY_PLAYER));
	box(wnd, 0, 0);
	wattroff(wnd, COLOR_PAIR(GRAY_PLAYER));
}

void	draw_status(t_vm *vm)
{
	if (vm->vs->control_button == SPACE)
		vm->vs->is_run = !vm->vs->is_run;
	vm->vs->curr_cursor_position = 2;
	wattron(vm->vs->win_info, A_BOLD);
	if (!vm->vs->is_run)
	{
		wattron(vm->vs->win_info, g_colors_players[3]);
		mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
				DEFAULT_CUSTOM_INDENT, "PAUSED\t\t");
		wattroff(vm->vs->win_info, g_colors_players[3]);
	}
	else
	{
		wattron(vm->vs->win_info, g_colors_players[1]);
		mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
				DEFAULT_CUSTOM_INDENT, "RUNNING\t\t");
		wattroff(vm->vs->win_info, g_colors_players[1]);
	}
	wattroff(vm->vs->win_info, A_BOLD);
}

void	draw_aff(t_vm *vm)
{
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Aff value : ");
	wprintw(vm->vs->win_info, "\t\t\t%d ", vm->vs->aff_symbol);
	if (ft_isprint(vm->vs->aff_symbol))
	{
		waddch(vm->vs->win_info, (const chtype)' ');
		waddstr(vm->vs->win_info, "'");
		wattron(vm->vs->win_info,
				g_colors_players[vm->vs->aff_owner]);
		waddch(vm->vs->win_info, (const chtype)vm->vs->aff_symbol);
		wattroff(vm->vs->win_info,
				g_colors_players[vm->vs->aff_owner]);
		waddstr(vm->vs->win_info, "'");
		waddch(vm->vs->win_info, (const chtype)' ');
		waddch(vm->vs->win_info, (const chtype)' ');
	}
	else
		wprintw(vm->vs->win_info, "  NONE!  ");
	vm->vs->curr_cursor_position += 2;
}
