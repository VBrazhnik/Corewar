/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:59:24 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/26 16:32:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

static void	fill_map(t_vm *vm, int32_t pc, int32_t len, int32_t player_id)
{
	int32_t i;
	int32_t value;

	i = pc;
	value = ((player_id - 1) % MAX_PLAYER_ID) + 1;
	while (i < len + pc)
	{
		vm->vs->map[i].index = value;
		i++;
	}
}

static void	init_map(t_vm *vm)
{
	int32_t	pc;
	int32_t	id;

	pc = 0;
	id = 1;
	while (id <= vm->players_num)
	{
		fill_map(vm, pc, vm->players[INDEX(id)]->code_size, id);
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}

static void	init_cursors(t_vm *vm)
{
	t_cursor *current;

	current = vm->cursors;
	while (current)
	{
		draw_cursor(vm, current);
		current = current->next;
	}
}

void		configure_vs(t_vm *vm)
{
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(false);
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	init_colors();
	init_map(vm);
	vm->vs->win_arena = newwin(HEIGHT, WIDTH + 4, 1, 2);
	vm->vs->win_info = newwin(HEIGHT, WIDTH / 4 + 10, 1, WIDTH + 6);
	vm->vs->win_help = newwin(HEIGHT / 5, WIDTH, HEIGHT + 2, 2);
	init_cursors(vm);
}
