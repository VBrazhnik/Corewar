/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:10:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/26 12:25:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_op.h"
#include "corewar_vs.h"
#include <errno.h>

static void	update_flags(t_vm *vm)
{
	if (vm->vs)
	{
		vm->dump_cycle = -1;
		vm->show_cycle = -1;
		vm->display_aff = false;
		vm->log = 0;
	}
}

int			main(int argc, char **argv)
{
	t_vm *vm;

	errno = 0;
	if (argc >= 2)
	{
		parse_corewar_args(argc, argv, (vm = init_vm()));
		update_flags(vm);
		init_arena(vm);
		set_cursors(vm);
		if (!vm->vs)
		{
			print_intro(vm->players, vm->players_num);
			exec(vm);
			print_last_alive(vm);
		}
		else
			exec_vs(vm);
		free_vm(&vm);
	}
	else
		print_help();
	return (0);
}
