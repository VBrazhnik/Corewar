/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:04:36 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 16:04:37 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error_msg.h"

t_player	*init_player(int id)
{
	t_player	*player;

	if (!(player = (t_player *)ft_memalloc(sizeof(t_player))))
		terminate(ERR_PLAYER_INIT);
	player->id = id;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = 0;
	player->code = NULL;
	player->last_live = 0;
	player->lives_num = 0;
	player->next = NULL;
	return (player);
}

t_cursor	*init_cursor(int32_t player_id,
						uint32_t pc,
						uint8_t op_code,
						int cycles_to_exec)
{
	t_cursor		*cursor;
	static uint32_t	cursor_id;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		terminate(ERR_CURSOR_INIT);
	cursor->id = ++cursor_id;
	cursor->carry = false;
	cursor->op_code = op_code;
	cursor->cycles_to_exec = cycles_to_exec;
	cursor->pc = pc;
	cursor->next = NULL;
	cursor->reg[0] = player_id;
	return (cursor);
}

t_vm		*init_vm(void)
{
	t_vm	*vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		terminate(ERR_VM_INIT);
	vm->players_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->cycles = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->checks_num = 0;
	vm->vs = NULL;
	vm->dump = -1;
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
	while (id <= MAX_PLAYERS)
	{
		if (vm->players[id - 1])
		{
			ft_memcpy(&(vm->arena[pc]),
				vm->players[id - 1]->code,
				(size_t)(vm->players[id - 1]->code_size));
			pc += MEM_SIZE / vm->players_num;
		}
		id++;
	}
}
