/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:14:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 16:20:20 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_cursor(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

void	set_cursors(t_vm *vm)
{
	int32_t		id;
	uint32_t	pc;

	id = 1;
	pc = 0;
	while (id <= vm->players_num)
	{
		add_cursor(&(vm->cursors), init_cursor(vm->players[INDEX(id)], pc));
		vm->cursors_num++;
		pc += MEM_SIZE / vm->players_num;
		id++;
	}
}
