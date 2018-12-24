/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:39:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 21:30:59 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static void	draw_arena(t_vm *vm)
{
	int			i;
	int			j;
	uint32_t	attribute;

	i = 0;
	while (i < 64)
	{
		j = 0;
		wmove(vm->vs->win_arena, i + 2, 5);
		while (j < 64)
		{
			attribute = check_attributes(vm, &vm->vs->map[i * 64 + j]);
			wattron(vm->vs->win_arena, attribute);
			wprintw(vm->vs->win_arena, "%.2x", vm->arena[i * 64 + j]);
			wattroff(vm->vs->win_arena, attribute);
			waddch(vm->vs->win_arena, ' ');
			j++;
		}
		wprintw(vm->vs->win_arena, "\n");
		i++;
	}
}

static void	draw_border(WINDOW *win)
{
	wattron(win, COLOR_PAIR(GRAY_PLAYER));
	box(win, 0, 0);
	wattroff(win, COLOR_PAIR(GRAY_PLAYER));
}

void		draw(t_vm *vm)
{
	draw_arena(vm);
	draw_info(vm);
	draw_border(vm->vs->win_arena);
	wrefresh(vm->vs->win_info);
	wrefresh(vm->vs->win_arena);
	wrefresh(vm->vs->win_help);
}
