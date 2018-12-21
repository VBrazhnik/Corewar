/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:48:48 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/20 23:10:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

t_vs	*init_vs(void)
{
	t_vs	*vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		terminate(ERR_VS_INIT);
	initscr();
	keypad(stdscr, TRUE);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	colors();
	return (vs);
}

void	initial_drawing(t_vm *vm)
{
	fill_id_map(vm);
	vm->vs->win_arena = newwin(HEIGHT, WIDTH + 4, 2, 2);
	vm->vs->win_info = newwin(HEIGHT, WIDTH / 4 + 10, 2, WIDTH + 6);
	vm->vs->win_help = newwin(HEIGHT / 5, WIDTH, HEIGHT + 2, 2);
	vm->vs->speed = DEFAULT_SPEED;
	pre_draw_cursors(vm);
}
