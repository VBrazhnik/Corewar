/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:46:00 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/02 20:50:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"
#include "corewar_vs_lib.h"

void	update_op_code(t_vm *vm, t_cursor *current)
{
	current->op_code = vm->arena[current->pc];
	if (vm->arena[current->pc] >= 0x01 && vm->arena[current->pc] <= 0x10)
		current->cycles_to_exec = g_op[INDEX(current->op_code)].cycles;
}

void	move_cursor(t_vm *vm, t_cursor *cursor)
{
	if (vm->vs)
		clear_cursor(vm, cursor);
	cursor->pc += cursor->step;
	cursor->pc = calc_addr(cursor->pc);
	if (vm->vs)
		draw_cursor(vm, cursor);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

void	delete_cursors(t_vm *vm)
{
	t_cursor	*current;
	t_cursor	*del;

	current = vm->cursors;
	while (current)
	{
		del = current;
		current = current->next;
		if (vm->log & DEATH_LOG)
			log_cursor_death(vm, del);
		if (vm->vs)
			clear_cursor(vm, del);
		ft_memdel((void **)&del);
	}
}
