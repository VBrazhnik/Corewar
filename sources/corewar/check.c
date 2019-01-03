/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:49:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/26 09:23:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_vs.h"

static void		reset_lives_nums(t_vm *vm)
{
	int32_t		i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->players[i]->previous_lives_num = vm->players[i]->current_lives_num;
		vm->players[i]->current_lives_num = 0;
		i++;
	}
	vm->lives_num = 0;
}

static t_bool	is_died(t_vm *vm, t_cursor *cursor)
{
	return (vm->cycles_to_die <= 0
			|| vm->cycles - cursor->last_live >= vm->cycles_to_die);
}

static void		delete_died_cursors(t_vm *vm)
{
	t_cursor	*previous;
	t_cursor	*current;
	t_cursor	*delete;

	previous = NULL;
	current = vm->cursors;
	while (current)
		if (is_died(vm, (delete = current)) && vm->cursors_num--)
		{
			current = current->next;
			if (vm->cursors == delete)
				vm->cursors = current;
			if (previous)
				previous->next = current;
			if (vm->log & DEATH_LOG)
				log_cursor_death(vm, delete);
			if (vm->vs)
				clear_cursor(vm, delete);
			ft_memdel((void **)&delete);
		}
		else
		{
			previous = current;
			current = current->next;
		}
}

void			cycles_to_die_check(t_vm *vm)
{
	vm->checks_num++;
	delete_died_cursors(vm);
	if (vm->checks_num == MAX_CHECKS || vm->lives_num >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->log & CYCLE_LOG)
			log_cycles_to_die(vm->cycles_to_die);
		vm->checks_num = 0;
	}
	reset_lives_nums(vm);
	vm->cycles_after_check = 0;
}
