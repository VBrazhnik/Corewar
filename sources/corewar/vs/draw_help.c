/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:18:13 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 19:14:05 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static void	draw_main_commands(t_vm *vm)
{
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 10,
			"Start/Pause - 'SPACE'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 2,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 10,
			"Exit - 'ESC'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 4,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 10,
			"Pass one cycle - 'S'");
}

static void	draw_additional_commands(t_vm *vm)
{
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 18,
			"Default speed - 'D'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 2,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 18,
			"Sound ON/OFF - 'M'");
}

static void	draw_speed_up_commands(t_vm *vm)
{
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 27,
			"Speed UP");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 2,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 27,
			"* By 1 - 'E'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 4,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 27,
			"* By 10 - 'R'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 6,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 27,
			"* By 100 - 'T'");
}

static void	draw_speed_down_commands(t_vm *vm)
{
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 33,
			"Speed DOWN");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 2,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 33,
			"* By 1 - 'Q'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 4,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 33,
			"* By 10 - 'A'");
	mvwprintw(vm->vs->win_help,
			vm->vs->help_cursor_position + 6,
			DEFAULT_CUSTOM_INDENT + TAB_LEN * 33,
			"* By 100 - 'Z'");
}

void		draw_help(t_vm *vm)
{
	wattron(vm->vs->win_help, A_BOLD);
	vm->vs->help_cursor_position = 2;
	draw_main_commands(vm);
	draw_additional_commands(vm);
	draw_speed_up_commands(vm);
	draw_speed_down_commands(vm);
	wattroff(vm->vs->win_help, A_BOLD);
}