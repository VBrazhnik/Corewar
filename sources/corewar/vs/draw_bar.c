/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:14:33 by ablizniu          #+#    #+#             */
/*   Updated: 2019/01/03 02:00:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static size_t	calc_bar_length(size_t lives, size_t sum_lives)
{
	size_t result;

	result = (lives * BAR_LENGTH) / sum_lives;
	if ((lives * BAR_LENGTH) % sum_lives >= sum_lives / 2)
		result++;
	return (result);
}

static void		draw_empty_bar(t_vm *vm)
{
	int i;

	i = 0;
	wattron(vm->vs->win_info, COLOR_PAIR(GRAY));
	while (i < BAR_LENGTH)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos + 1,
				DEFAULT_INDENT + i,
				"-");
		i++;
	}
	wattroff(vm->vs->win_info, COLOR_PAIR(GRAY));
}

static void		draw_bar(t_vm *vm, size_t len, size_t pos, int index)
{
	size_t i;

	i = pos;
	wattron(vm->vs->win_info, g_colors_players[index + 1]);
	while (i <= pos + len && i < BAR_LENGTH)
	{
		mvwprintw(vm->vs->win_info,
				vm->vs->cursor_pos + 1,
				(int)(DEFAULT_INDENT + i),
				"-");
		i++;
	}
	wattroff(vm->vs->win_info, g_colors_players[index + 1]);
}

void			draw_lives_bar(t_vm *vm, t_bool current)
{
	int		i;
	size_t	sum_lives;
	size_t	pos;
	size_t	len;

	i = 0;
	sum_lives = 0;
	while (i < vm->players_num)
		if (current)
			sum_lives += vm->players[i++]->current_lives_num;
		else
			sum_lives += vm->players[i++]->previous_lives_num;
	i = 0;
	pos = 0;
	if (!sum_lives)
		draw_empty_bar(vm);
	else
		while (i < vm->players_num)
		{
			len = calc_bar_length((current) ? vm->players[i]->current_lives_num
						: vm->players[i]->previous_lives_num, sum_lives);
			draw_bar(vm, len, pos, i++);
			pos += len;
		}
	vm->vs->cursor_pos++;
}
