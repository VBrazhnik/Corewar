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

#include "corewar_op.h"
#include <stdlib.h>

void	last_check_and_kill_all_processes(void)
{
}

void	nbr_live_condition(t_vm **vm)
{
	t_cursor	*cursor;
	uint32_t	sum;

	sum = 0;
	cursor = (*vm)->cursors;
	while (cursor)
	{
		sum += cursor->lives_num;
		if (cursor->lives_num == 0)
		{
			printf("NEED DEBUG!\n");
			exit(0);
		}
		cursor = cursor->next;
	}
	if (sum >= NBR_LIVE)
		(*vm)->cycles_to_die -= CYCLE_DELTA;
}

void	reset_lives_nums(t_vm *vm)
{
	int			i;
	t_cursor	*current;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->players[i])
			vm->players[i]->lives_num = 0;
		i++;
	}
	current = vm->cursors;
	while (current)
	{
		current->lives_num = 0;
		current = current->next;
	}
}

void	check_and_remove(t_vm **vm, t_cursor **cursor)
{
	t_cursor	*tmp;
	t_cursor	*iterator;

	while (*cursor && !(*cursor)->lives_num)
	{
		ft_putstr("deleted!\n");
		tmp = *cursor;
		*cursor = (*cursor)->next;
		ft_memdel((void **)&tmp);
		(*vm)->cursors_num--;
	}
	iterator = *cursor;
	while (iterator && iterator->next)
	{
		if (!iterator->next->lives_num)
		{
			ft_putstr("deleted!\n");
			tmp = iterator->next;
			iterator->next = iterator->next->next;
			ft_memdel((void **)&tmp);
			(*vm)->cursors_num--;
			continue ;
		}
		if (iterator->next)
			iterator = iterator->next;
	}
}

void	max_checks_conditon(t_vm **vm, ssize_t *cycle_buff)
{
	if ((*vm)->cycles_to_die == *cycle_buff)
	{
		if ((*vm)->checks_num == MAX_CHECKS)
		{
			(*vm)->cycles_to_die -= CYCLE_DELTA;
			*cycle_buff = (*vm)->cycles_to_die;
			(*vm)->checks_num = 0;
		}
	}
}

t_bool	rules(t_vm **vm)
{
	printf("!Rules\n");
	check_and_remove(vm, &(*vm)->cursors);
	nbr_live_condition(vm);
	reset_lives_nums(*vm);
	if (!((*vm)->cursors_num))
		return (false);
	return (true);
}

void	exec(t_vm *vm)
{
	t_cursor	*current;
	ssize_t		cycle_buff;
//TODO расхождение на 4940 итерации
	vm->cycles = 0;
	cycle_buff = vm->cycles_to_die;
	while (vm->cycles_to_die >= 0)
	{
		vm->cycles++;
		vm->main_cycle++;
		current = vm->cursors;
		max_checks_conditon(&vm, &cycle_buff);
		while (current)
		{
			operations(current, &vm);
			current = current->next;
		}
		if (vm->main_cycle && (vm->cycles_to_die == vm->main_cycle))
		{
			vm->checks_num++;
			if (!rules(&vm))
				break ;
			vm->main_cycle = 0;
		}
		if (vm->cycles_to_die == 0)
			last_check_and_kill_all_processes();
	}
	print_arena((*vm).arena);
}

t_bool	has_arg_types_code(uint8_t op_code)
{
	if (op_code > 0 && op_code <= 0x10)
		return (g_op[INDEX(op_code)].args_types_code);
	return (false);
}

void	operations(t_cursor *cursor, t_vm **vm)
{
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (!cursor->cycles_to_exec)
	{
		parse_arg_types(vm, &cursor);
		if (validate_arg_types(&cursor) && validate_args(&cursor, vm))
		{
			g_op[INDEX(cursor->op_code)].func(vm, &cursor, g_op[INDEX(cursor->op_code)]);
			cursor->pc += cursor->step;
			if ((*vm)->arena[cursor->pc] > 0 && (*vm)->arena[cursor->pc] <= 0x10)
			{
				cursor->op_code = (*vm)->arena[cursor->pc];
				cursor->cycles_to_exec = g_op[INDEX(cursor->op_code)].cycles;
			}
			else
				cursor->op_code = 0;
			printf("pc: %4d | cycle: %u |", cursor->pc, (unsigned int)(*vm)->cycles);
			if ((cursor->op_code) > 0 && (cursor)->op_code <= 16)
				printf(" op: %5s | id: %2d \n", g_op[INDEX(cursor->op_code)].name, cursor->id);
		}
		else
		{
			cursor->step += OP_CODE_LEN + ((has_arg_types_code(cursor->op_code)) ? ARGS_CODE_LEN : 0);
			cursor->step += calc_step(&cursor);
			cursor->pc += cursor->step;
			if ((*vm)->arena[cursor->pc] > 0 && (*vm)->arena[cursor->pc] <= 0x10)
			{
				cursor->op_code = (*vm)->arena[cursor->pc];
				cursor->cycles_to_exec = g_op[INDEX(cursor->op_code)].cycles;
			}
			else
				cursor->op_code = 0;
		}
		cursor->pc = calc_addr(cursor->pc);
		ft_bzero(cursor->args_types, 3);
		cursor->step = 0;
	}
}
