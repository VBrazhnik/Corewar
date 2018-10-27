/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:10:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 15:10:03 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

void	add_cursor(t_cursor **list, t_cursor *new)
{
	t_cursor	*iterator;

	if (list && new)
	{
		if (*list)
		{
			iterator = *list;
			while (iterator->next)
				iterator = iterator->next;
			iterator->next = new;
		}
		else
			*list = new;
	}
}

void	init_cursors(t_vm *vm)
{
	uint32_t	id;
	uint32_t	pc;
	uint8_t		op_code;
	int			cycles_to_exec;

	id = MAX_PLAYERS;
	pc = MEM_SIZE - MEM_SIZE / vm->players_num;
	cycles_to_exec = 0;
	while (id >= 1)
	{
		if (vm->players[id - 1])
		{
			if ((op_code = vm->arena[pc]) >= 0x01 && op_code <= 0x10)
				cycles_to_exec = g_op[op_code - 1].cycles;
			add_cursor(&(vm->cursors),
					init_cursor(id, pc, op_code, cycles_to_exec));
			pc -= MEM_SIZE / vm->players_num;
		}
		id--;
	}
}

int		main(int argc, char **argv)
{
	t_vm	*vm;

	errno = 0;
	if (argc >= 2)
	{
		parse_args(argc, argv, (vm = init_vm()));
		init_arena(vm);
		init_cursors(vm);
		print_arena(vm->arena);
	}
	else
		print_help();
	return (0);
}
