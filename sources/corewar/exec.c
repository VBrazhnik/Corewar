/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:17 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 16:29:30 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"
#include <stdlib.h>

void		last_exec(t_vm *vm)
{
	t_cursor	*current;
	t_cursor	*del;

	vm->cycles++;
	if (vm->log & CYCLE_LEVEL)
		log_cycle(vm->cycles);
	current = vm->cursors;
	while (current)
	{
		exec_op(current, vm);
		current = current->next;
	}
	current = vm->cursors;
	while (current)
	{
		del = current;
		current = current->next;
		if (vm->log & DEATH_LEVEL)
			log_cursor_death(vm, del);
		ft_memdel((void **)&del);
	}
}

void		update_op_code(t_vm *vm)
{
	t_cursor	*current;

	current = vm->cursors;
	while (current)
	{
		if (current->cycles_to_exec == 0)
		{
			current->op_code = vm->arena[current->pc];
			if (vm->arena[current->pc] > 0 && vm->arena[current->pc] <= 0x10)
				current->cycles_to_exec = g_op[INDEX(current->op_code)].cycles;
		}
		current = current->next;
	}
}

void		exec(t_vm *vm)
{
	t_cursor	*current;

	while (vm->cycles_to_die >= 0)
	{
		update_op_code(vm);
		if (vm->dump == vm->cycles)
			print_arena(vm->arena);
		vm->cycles++;
		vm->cycles_after_check++;
		if (vm->log & CYCLE_LEVEL)
			log_cycle(vm->cycles);
		current = vm->cursors;
		while (current)
		{
			exec_op(current, vm);
			current = current->next;
		}
		if (vm->cycles && (vm->cycles_to_die == vm->cycles_after_check))
			cycles_to_die_check(&vm);
		if (vm->cycles_to_die <= 0)
			last_exec(vm);
		if (!vm->cursors_num)
			break ;
	}
}

void		update_cursor(t_cursor *cursor)
{
	cursor->pc += cursor->step;
	cursor->pc = calc_addr(cursor->pc);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

void		exec_op(t_cursor *cursor, t_vm *vm)
{
	t_op	*op;

	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (!cursor->cycles_to_exec)
	{
		op = NULL;
		if (cursor->op_code > 0 && cursor->op_code <= 0x10)
			op = &g_op[INDEX(cursor->op_code)];
		if (op)
		{
			parse_arg_types(vm, cursor, op);
			if (valid_arg_types(cursor, op) && valid_args(cursor, vm, op))
				(*op).func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
			if (vm->log & PC_LEVEL && cursor->step)
				log_pc_movements(vm->arena, cursor);
		}
		else
			cursor->step = OP_CODE_LEN;
		update_cursor(cursor);
	}
}
