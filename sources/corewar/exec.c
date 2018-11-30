/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:17 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/30 19:32:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

void	update_op_code(t_vm *vm, t_cursor *current)
{
	current->op_code = vm->arena[current->pc];
	if (vm->arena[current->pc] >= 0x01 && vm->arena[current->pc] <= 0x10)
		current->cycles_to_exec = g_op[INDEX(current->op_code)].cycles;
	else
		current->cycles_to_exec = 0;
}

void	move_cursor(t_cursor *cursor)
{
	cursor->pc += cursor->step;
	cursor->pc = calc_addr(cursor->pc);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

void	exec_op(t_cursor *cursor, t_vm *vm)
{
	t_op	*op;

	if (cursor->cycles_to_exec == 0)
		update_op_code(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
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
			if (vm->log & PC_MOVEMENT_LOG && cursor->step)
				log_pc_movements(vm->arena, cursor);
		}
		else
			cursor->step = OP_CODE_LEN;
		move_cursor(cursor);
	}
}

void	exec_cycle(t_vm *vm)
{
	t_cursor	*current;

	vm->cycles++;
	vm->cycles_after_check++;
	if (vm->log & CYCLE_LOG)
		log_cycle(vm->cycles);
	current = vm->cursors;
	while (current)
	{
		exec_op(current, vm);
		current = current->next;
	}
}

void	exec(t_vm *vm)
{
	while (vm->cycles_to_die > 0 && vm->cursors_num)
	{
		if (vm->dump == vm->cycles)
		{
			print_arena(vm->arena);
			exit(0);
		}
		if (vm->drop > 0 && !(vm->cycles % vm->drop))
		{
			print_arena(vm->arena);
			while (getchar() != '\n')
				;
		}
		exec_cycle(vm);
		if (vm->cycles && (vm->cycles_to_die == vm->cycles_after_check))
			cycles_to_die_check(&vm);
	}
	if (vm->cycles_to_die <= 0 && vm->cursors_num)
		exec_cycle(vm);
	free_cursors(vm);
}
