/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_widgets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:14:33 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 17:08:06 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void		draw_empty_widget(t_vm *vm)
{
	size_t i;

	i = 0;
	wattroff(vm->vs->win_info, A_BOLD);
	wattron(vm->vs->win_info, g_colors_players[0]);
	while (i < WIDGET_LEN)
	{
		mvwprintw(vm->vs->win_info, vm->vs->cursor_pos,
				DEFAULT_CUSTOM_INDENT + i, "-");
		i++;
	}
	wattroff(vm->vs->win_info, g_colors_players[0]);
	wattron(vm->vs->win_info, A_BOLD);
}

void		draw_widget(t_vm *vm, int32_t len, size_t pos, int32_t index)
{
	size_t	i;

	i = pos;
	wattron(vm->vs->win_info, g_colors_players[index + 1]);
	while (i <= len + pos)
	{
		if (i >= WIDGET_LEN)
			break ;
		mvwprintw(vm->vs->win_info, vm->vs->cursor_pos,
				DEFAULT_CUSTOM_INDENT + i, "-");
		i++;
	}
	wattroff(vm->vs->win_info, g_colors_players[index + 1]);
}

void		draw_live_breakdown(t_vm *vm,
								size_t total_live_in_per, char *period)
{
	int32_t	i;
	size_t	pos;
	int32_t	live_breakdown;

	i = 0;
	pos = 0;
	mvwprintw(vm->vs->win_info, vm->vs->cursor_pos,
			DEFAULT_CUSTOM_INDENT, "Live breakdown for ");
	wprintw(vm->vs->win_info, "%s period :", period);
	vm->vs->cursor_pos += 1;
	if (!total_live_in_per)
		draw_empty_widget(vm);
	else
		while (i < vm->players_num)
		{
			live_breakdown = calc_percent(
					(ft_strequ("current", period)) ?
					vm->players[i]->lives_num : vm->vs->players_lives[i],
					total_live_in_per);
			draw_widget(vm, live_breakdown, pos, i);
			pos += live_breakdown;
			i++;
		}
	vm->vs->cursor_pos += 2;
}
