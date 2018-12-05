/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:10:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/05 21:54:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op.h"
#include <errno.h>

void	add_cursor(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

void	init_cursors(t_vm *vm)
{
	uint32_t	id;
	uint32_t	pc;

	id = 1;
	pc = 0;
	while (id <= vm->players_num)
	{
		add_cursor(&(vm->cursors), init_cursor(-id, pc));
		vm->cursors_num++;
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}

void	update_flags(t_vm *vm)
{
	if (vm->vs)
	{
		vm->dump_cycle = -1;
		vm->show_cycle = -1;
		vm->display_aff = false;
		vm->log = 0;
	}
}

int		main(int argc, char **argv)
{
	t_vm	*vm;

	errno = 0;
	if (argc >= 2)
	{
		parse_args(argc, argv, (vm = init_vm()));
		update_flags(vm);
		init_arena(vm);
		init_cursors(vm);
		if (!vm->vs)
			print_intro(vm->players, vm->players_num);
		exec(vm);
		if (!vm->vs)
			print_last_alive(vm);
		free_players(vm->players, vm->players_num);
		ft_memdel((void **)&vm);
	}
	else
		print_help();
	return (0);
}
