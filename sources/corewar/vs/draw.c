/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:39:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/28 18:38:33 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static void	draw_arena(t_vm *vm)
{
	static ssize_t	cycles = 0;
	int				i;
	int				j;
	int				attribute;

	i = 0;
	while (i < 64)
	{
		j = 0;
		wmove(vm->vs->win_arena, i + 2, 5);
		while (j < 64)
		{
			attribute = get_attribute(vm, &vm->vs->map[i * 64 + j], cycles);
			wattron(vm->vs->win_arena, attribute);
			wprintw(vm->vs->win_arena, "%.2x", vm->arena[i * 64 + j]);
			wattroff(vm->vs->win_arena, attribute);
			waddch(vm->vs->win_arena, ' ');
			j++;
		}
		wprintw(vm->vs->win_arena, "\n");
		i++;
	}
	cycles = vm->cycles;
}

static void	draw_border(WINDOW *win)
{
	wattron(win, COLOR_PAIR(GRAY));
	box(win, 0, 0);
	wattroff(win, COLOR_PAIR(GRAY));
}

void		draw(t_vm *vm)
{
	werase(vm->vs->win_arena);
	werase(vm->vs->win_info);
	werase(vm->vs->win_help);
	draw_arena(vm);
	draw_info(vm);
	draw_border(vm->vs->win_arena);
	wrefresh(vm->vs->win_info);
	wrefresh(vm->vs->win_arena);
	wrefresh(vm->vs->win_help);
}
