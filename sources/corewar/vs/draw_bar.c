/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:14:33 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/25 03:38:22 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static int32_t	calc_length(double part, double sum)
{
	double len;

	len = ((part / sum) * WIDGET_LEN);
	if ((len - (int32_t)(len)) >= 0.5)
		len++;
	return ((int32_t)len);
}

static void		draw_empty_bar(t_vm *vm)
{
	int i;

	i = 0;
	wattron(vm->vs->win_info, COLOR_PAIR(GRAY));
	while (i < WIDGET_LEN)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos + 1,
				DEFAULT_CUSTOM_INDENT + i,
				"-");
		i++;
	}
	wattroff(vm->vs->win_info, COLOR_PAIR(GRAY));
}

static void		draw_bar(t_vm *vm, int32_t len, int pos, int32_t index)
{
	int	i;

	i = pos;
	wattron(vm->vs->win_info, g_colors_players[index + 1]);
	while (i <= pos + len && i < WIDGET_LEN)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos + 1,
				DEFAULT_CUSTOM_INDENT + i,
				"-");
		i++;
	}
	wattroff(vm->vs->win_info, g_colors_players[index + 1]);
}

void			draw_current_lives_bar(t_vm *vm)
{
	int32_t	i;
	size_t	sum_lives;
	int		pos;
	int32_t	len;

	mvwprintw(vm->vs->win_info, vm->vs->cursor_pos += 3,
		DEFAULT_CUSTOM_INDENT, "Bar of lives for current period :");
	i = 0;
	sum_lives = 0;
	while (i < vm->players_num)
		sum_lives += vm->players[i++]->lives_num;
	i = 0;
	pos = 0;
	if (!sum_lives)
		draw_empty_bar(vm);
	else
		while (i < vm->players_num)
		{
			len = calc_length(vm->players[i]->lives_num, sum_lives);
			draw_bar(vm, len, pos, i);
			pos += len;
			i++;
		}
}

void			draw_previous_lives_bar(t_vm *vm)
{
	int32_t	i;
	size_t	sum_lives;
	int		pos;
	int32_t	len;

	mvwprintw(vm->vs->win_info, vm->vs->cursor_pos += 3,
		DEFAULT_CUSTOM_INDENT, "Bar of lives for previous period :");
	i = 0;
	sum_lives = 0;
	while (i < vm->players_num)
		sum_lives += vm->vs->players_lives[i++];
	i = 0;
	pos = 0;
	if (!sum_lives)
		draw_empty_bar(vm);
	else
		while (i < vm->players_num)
		{
			len = calc_length(vm->vs->players_lives[i], sum_lives);
			draw_bar(vm, len, pos, i);
			pos += len;
			i++;
		}
}
