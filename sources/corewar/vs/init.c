/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:48:48 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/25 02:35:12 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"
#include "corewar_error.h"

t_vs	*init_vs(void)
{
	t_vs *vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		terminate(ERR_VS_INIT);
	return (vs);
}

void	update_map(t_vm *vm, t_cursor *cursor, int32_t addr, int32_t size)
{
	int32_t value;

	value = ((cursor->player->id - 1) % MAX_PLAYER_ID) + 1;
	while (size)
	{
		vm->vs->map[calc_addr(addr + size - 1)].value = value;
		vm->vs->map[calc_addr(addr
							+ size - 1)].wait_cycles_store = CYCLE_TO_WAIT;
		size--;
	}
}
