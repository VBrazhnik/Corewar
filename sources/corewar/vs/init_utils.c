/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:10:33 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 23:10:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void			copy_players_id(t_vm *vm, int32_t pc,
				size_t len, int8_t players_id)
{
	size_t		i;

	i = pc;
	while (i < len + (size_t)pc)
	{
		players_id = (uint8_t)((players_id % MAX_PLAYER_ID) ?
				(players_id % MAX_PLAYER_ID) : (MAX_PLAYER_ID));
		vm->vs->map[i].value = (uint8_t)players_id;
		i++;
	}
}

void			fill_id_map(t_vm *vm)
{
	int32_t		pc;
	int8_t		id;

	pc = 0;
	id = 1;
	while (id <= vm->players_num)
	{
		copy_players_id(vm, pc, (size_t)vm->players[INDEX(id)]->code_size, id);
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}

void			pre_draw_cursors(t_vm *vm)
{
	t_cursor *iterator;

	iterator = vm->cursors;
	while (iterator)
	{
		draw_cursor(vm, iterator);
		iterator = iterator->next;
	}
}

void			fill_map(t_vm *vm)
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
