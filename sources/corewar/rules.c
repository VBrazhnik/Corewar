/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:18:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/11/23 09:18:55 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar.h"

void		reset_lives_nums(t_vm *vm)
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

t_bool		is_died(t_vm *vm, t_cursor *cursor)
{
	return (!cursor->lives_num
		&& vm->cycles - cursor->last_live >= vm->cycles_to_die);
}

void		del_died_cursors(t_vm *vm)
{
	t_cursor	*del;
	t_cursor	*iterator;

	while (vm->cursors && is_died(vm, vm->cursors))
	{
		if (vm->log & DEATH_LEVEL)
			log_cursor_death(vm, vm->cursors);
		del = vm->cursors;
		vm->cursors = (vm->cursors)->next;
		ft_memdel((void **)&del);
		vm->cursors_num--;
	}
	iterator = vm->cursors;
	while (iterator && iterator->next)
		if (is_died(vm, iterator->next))
		{
			del = iterator->next;
			if (vm->log & DEATH_LEVEL)
				log_cursor_death(vm, del);
			iterator->next = iterator->next->next;
			ft_memdel((void **)&del);
			vm->cursors_num--;
		}
		else
			iterator = iterator->next;
}

void		cycles_to_die_check(t_vm **vm)
{
	static ssize_t	cycles_to_die = CYCLE_TO_DIE;

	(*vm)->checks_num++;
	cycles_to_die = (*vm)->cycles_to_die;
	del_died_cursors(*vm);
	if (((*vm)->cycles_after_check == cycles_to_die
		&& (*vm)->checks_num == MAX_CHECKS)
		|| (calc_lives_num((*vm)->cursors) >= NBR_LIVE))
	{
		(*vm)->cycles_to_die -= CYCLE_DELTA;
		(*vm)->checks_num = 0;
	}
	reset_lives_nums(*vm);
	(*vm)->cycles_after_check = 0;
	if (((*vm)->log & CYCLE_LEVEL) && !(*vm)->checks_num)
		log_cycles_to_die((*vm)->cycles_to_die);
}
