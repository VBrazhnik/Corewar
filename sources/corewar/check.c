/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:49:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 18:12:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar.h"

static void		reset_lives_nums(t_vm *vm)
{
	int32_t		i;
	t_cursor	*current;

	i = 0;
	while (i < vm->players_num)
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

static t_bool	is_died(t_vm *vm, t_cursor *cursor)
{
	return (!cursor->lives_num
		&& vm->cycles - cursor->last_live >= vm->cycles_to_die);
}

static void		delete_died_cursors(t_vm *vm)
{
	t_cursor	*delete;
	t_cursor	*current;

	while (vm->cursors && is_died(vm, vm->cursors))
	{
		if (vm->log & DEATH_LOG)
			log_cursor_death(vm, vm->cursors);
		delete = vm->cursors;
		vm->cursors = (vm->cursors)->next;
		ft_memdel((void **)&delete);
		vm->cursors_num--;
	}
	current = vm->cursors;
	while (current && current->next)
		if (is_died(vm, current->next))
		{
			delete = current->next;
			if (vm->log & DEATH_LOG)
				log_cursor_death(vm, delete);
			current->next = current->next->next;
			ft_memdel((void **)&delete);
			vm->cursors_num--;
		}
		else
			current = current->next;
}

void			cycles_to_die_check(t_vm *vm)
{
	vm->checks_num++;
	delete_died_cursors(vm);
	if ((vm->cycles_after_check == vm->cycles_to_die
		&& vm->checks_num == MAX_CHECKS)
		|| (calc_lives_num(vm->cursors) >= NBR_LIVE))
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks_num = 0;
	}
	reset_lives_nums(vm);
	vm->cycles_after_check = 0;
	if ((vm->log & CYCLE_LOG) && !vm->checks_num)
		log_cycles_to_die(vm->cycles_to_die);
}
