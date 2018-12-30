/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:31:17 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 14:41:13 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"
#include "corewar_vs.h"

static void	exec_op(t_cursor *cursor, t_vm *vm)
{
	t_op *op;

	if (cursor->cycles_to_exec == 0)
		update_op_code(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		op = NULL;
		if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
			op = &g_op[INDEX(cursor->op_code)];
		if (op)
		{
			parse_types_code(vm, cursor, op);
			if (is_arg_types_valid(cursor, op) && is_args_valid(cursor, vm, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
			if (vm->log & PC_MOVEMENT_LOG && cursor->step)
				log_pc_movements(vm->arena, cursor);
		}
		else
			cursor->step = OP_CODE_LEN;
		move_cursor(vm, cursor);
	}
}

void		exec_cycle(t_vm *vm)
{
	t_cursor *current;

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

void		exec(t_vm *vm)
{
	while (vm->cursors_num)
	{
		if (vm->dump_cycle == vm->cycles)
		{
			print_arena(vm->arena, vm->dump_print_mode);
			exit(0);
		}
		if (vm->show_cycle > 0 && !(vm->cycles % vm->show_cycle))
		{
			print_arena(vm->arena, vm->show_print_mode);
			while (getchar() != '\n')
				;
		}
		exec_cycle(vm);
		if (vm->cycles_to_die == vm->cycles_after_check
			|| vm->cycles_to_die <= 0)
			cycles_to_die_check(vm);
	}
}
