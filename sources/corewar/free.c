/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:01:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/11/29 18:48:39 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_cursors(t_vm *vm)
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
		ft_memdel((void **)&del);
	}
}

void		free_players(t_player **players)
{
	int		id;

	id = 1;
	while (id <= MAX_PLAYERS)
	{
		if (players[INDEX(id)])
		{
			ft_strdel(&(players[INDEX(id)]->name));
			ft_strdel(&(players[INDEX(id)]->comment));
			ft_memdel((void **)&(players[INDEX(id)]->code));
			ft_memdel((void **)&players[INDEX(id)]);
		}
		id++;
	}
}
