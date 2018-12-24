/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:56:54 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 16:39:03 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static void	draw_players(t_vm *vm)
{
	int32_t i;

	i = 0;
	vm->vs->cursor_pos += 2;
	while (i < vm->players_num)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos++,
				DEFAULT_CUSTOM_INDENT,
				"Player %d : ", -(vm->players[i]->id));
		wattron(vm->vs->win_info, g_colors_players[vm->players[i]->id]);
		wprintw(vm->vs->win_info, "%.40s", vm->players[i]->name);
		wattroff(vm->vs->win_info, g_colors_players[vm->players[i]->id]);
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos++,
				DEFAULT_CUSTOM_INDENT,
				"%-32s %-10zd", "   Last live :", vm->players[i]->last_live);
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos++,
				DEFAULT_CUSTOM_INDENT,
				"%-32s %-10zu", "   Lives in current period :",
				vm->players[i]->lives_num);
		vm->vs->cursor_pos++;
		i++;
	}
}

static void	draw_game_params(t_vm *vm)
{
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos,
			DEFAULT_CUSTOM_INDENT,
			"%-32s %-10zd", "Cycle to die :", vm->cycles_to_die);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"%-32s %-10zu", "Cycle delta :", CYCLE_DELTA);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"%-32s %.5zu/%zu", "Lives :",
			calc_lives_num(vm->cursors), NBR_LIVE);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"%-32s %.5zu", "Cycles to check :", (vm->cycles_to_die > 0) ?
			vm->cycles_to_die - vm->cycles_after_check : 0);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"%-32s %.5zu/%zu", "Checks :",
			vm->checks_num, MAX_CHECKS);
}

static void	draw_aff(t_vm *vm)
{
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"%-32s ", "Aff value :");
	wattron(vm->vs->win_info, g_colors_players[vm->vs->aff_player->id]);
	wprintw(vm->vs->win_info, "%#0.2x", vm->vs->aff_symbol);
	if (ft_isprint(vm->vs->aff_symbol))
		wprintw(vm->vs->win_info, " '%c'", vm->vs->aff_symbol);
	wattroff(vm->vs->win_info, g_colors_players[vm->vs->aff_player->id]);
}

static void	draw_winner(t_vm *vm)
{
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 15,
			DEFAULT_CUSTOM_INDENT,
			"The winner is ");
	wattron(vm->vs->win_info, g_colors_players[vm->last_alive->id]);
	wprintw(vm->vs->win_info, "%.38s", vm->last_alive->name);
	wattroff(vm->vs->win_info, g_colors_players[vm->last_alive->id]);
}

void		draw_info(t_vm *vm)
{
	wattron(vm->vs->win_info, A_BOLD);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"Cycles/second : %-6d", vm->vs->speed);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 3,
			DEFAULT_CUSTOM_INDENT,
			"Cycle : %-6zd", vm->cycles);
	mvwprintw(vm->vs->win_info,
			vm->vs->cursor_pos += 2,
			DEFAULT_CUSTOM_INDENT,
			"Cursors : %-6zu", vm->cursors_num);
	draw_players(vm);
	draw_live_breakdown(vm, vm->vs->total_lives_in_curr_per, "current");
	draw_live_breakdown(vm, vm->vs->total_lives_in_last_per, "last");
	draw_game_params(vm);
	if (vm->vs->aff_player)
		draw_aff(vm);
	if (!vm->cursors_num)
		draw_winner(vm);
	draw_sounds_status(vm);
	draw_help_status(vm);
	wattroff(vm->vs->win_info, A_BOLD);
}
