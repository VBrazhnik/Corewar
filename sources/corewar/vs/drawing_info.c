/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:56:54 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 23:20:50 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void	drawing_main_info(t_vm *vm)
{
	if (vm->cycles_to_die <= 0)
		vm->cycles_to_die = 0;
	wattron(vm->vs->win_info, A_BOLD);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cycles/second : %d   ", vm->vs->speed);
	vm->vs->curr_cursor_position += 3;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cycle : %d", vm->cycles);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cursors : %d  ", vm->cursors_num);
	drawing_players_info(vm);
	draw_live_breakdown(vm, vm->vs->total_lives_in_curr_per, "current");
	draw_live_breakdown(vm, vm->vs->total_lives_in_last_per, "last");
	drawing_final_info(vm);
	draw_aff(vm);
	if (vm->cycles_to_die <= 0 || !vm->cursors_num)
		draw_winner(vm);
	sound_player_status(vm);
	draw_help(vm);
	wattroff(vm->vs->win_info, A_BOLD);
}

void	drawing_players_info(t_vm *vm)
{
	int32_t i;

	i = 0;
	vm->vs->curr_cursor_position += 2;
	while (i < vm->players_num)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->curr_cursor_position + (i * 4), DEFAULT_CUSTOM_INDENT,
				"Player %d : ", -vm->players[i]->id);
		wattron(vm->vs->win_info,
				g_colors_players[FT_ABS((vm->players[i]->id))]);
		wprintw(vm->vs->win_info, "%.35s\n",
				clear_name(vm->players[i]->name));
		wattroff(vm->vs->win_info,
				g_colors_players[FT_ABS((vm->players[i]->id))]);
		wprintw(vm->vs->win_info, "\t  Last live : \t\t\t%d\n",
				vm->players[i]->last_live);
		wprintw(vm->vs->win_info, "\t  Lives in current period : \t%d\n",
				vm->players[i]->lives_num);
		i++;
	}
	vm->vs->curr_cursor_position += i * 4;
}

void	draw_help(t_vm *vm)
{
	vm->vs->curr_cursor_position = HEIGHT - 3;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Press 'H' to ");
	if (!vm->vs->display_help)
	{
		wprintw(vm->vs->win_info, "show");
		if (vm->vs->win_help)
		{
			delwin(vm->vs->win_help);
			vm->vs->win_help = newwin(HEIGHT / 5, WIDTH, HEIGHT + 2, 2);
		}
	}
	else
	{
		wprintw(vm->vs->win_info, "hide");
		print_instructions(vm);
	}
	wprintw(vm->vs->win_info, " help.");
}

void	draw_winner(t_vm *vm)
{
	if (!vm->vs->end)
	{
		play_winner(vm);
		vm->vs->end = true;
	}
	vm->vs->curr_cursor_position += 15;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "The winner is : ");
	wattron(vm->vs->win_info, g_colors_players[vm->last_alive->id]);
	wprintw(vm->vs->win_info, "%.35s ", clear_name(vm->last_alive->name));
	wattroff(vm->vs->win_info, g_colors_players[vm->last_alive->id]);
	vm->vs->curr_cursor_position += 2;
	wattron(vm->vs->win_info, A_BLINK);
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Press any key to finish");
	wattroff(vm->vs->win_info, A_BLINK);
	if (vm->vs->control_button > 0)
		free_vs(vm);
}

void	drawing_final_info(t_vm *vm)
{
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cycle to die : \t\t\t%zu    ",
			vm->cycles_to_die);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cycle delta : \t\t\t%d", CYCLE_DELTA);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Lives : \t\t\t\t%.5zu/%zu\t",
			calc_lives_num(vm->cursors), NBR_LIVE);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Cycles to check : \t\t%.5zu\t\t",
			vm->cycles_to_die - vm->cycles_after_check, MAX_CHECKS);
	vm->vs->curr_cursor_position += 2;
	mvwprintw(vm->vs->win_info, vm->vs->curr_cursor_position,
			DEFAULT_CUSTOM_INDENT, "Checks : \t\t\t%zu/%zu",
			vm->checks_num, MAX_CHECKS);
	vm->vs->curr_cursor_position += 2;
}
