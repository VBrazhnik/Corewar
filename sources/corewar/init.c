/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:04:36 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/23 17:12:30 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error.h"

t_player	*init_player(int id)
{
	t_player *player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		terminate(ERR_PLAYER_INIT);
	player->id = id;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = 0;
	player->code = NULL;
	player->last_live = 0;
	player->current_lives_num = 0;
	player->previous_lives_num = 0;
	player->next = NULL;
	return (player);
}

t_cursor	*init_cursor(t_player *player, int32_t pc)
{
	t_cursor		*cursor;
	static uint32_t	cursor_id;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		terminate(ERR_CURSOR_INIT);
	cursor->id = ++cursor_id;
	cursor->carry = false;
	cursor->op_code = 0;
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->pc = pc;
	cursor->next = NULL;
	cursor->reg[INDEX(1)] = -(player->id);
	cursor->player = player;
	return (cursor);
}

t_vm		*init_vm(void)
{
	t_vm *vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		terminate(ERR_VM_INIT);
	vm->players_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->lives_num = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_after_check = 0;
	vm->checks_num = 0;
	vm->vs = NULL;
	vm->dump_cycle = -1;
	vm->dump_print_mode = 0;
	vm->show_cycle = -1;
	vm->show_print_mode = 0;
	vm->display_aff = false;
	vm->log = 0;
	return (vm);
}

void		init_arena(t_vm *vm)
{
	int			id;
	uint32_t	pc;

	id = 1;
	pc = 0;
	while (id <= vm->players_num)
	{
		ft_memcpy(&(vm->arena[pc]),
			vm->players[INDEX(id)]->code,
			(size_t)(vm->players[INDEX(id)]->code_size));
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}
