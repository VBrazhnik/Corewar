/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:48:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 18:15:09 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>
#include <errno.h>

void			terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(0);
}

t_bool			is_filename(const char *filename, const char *ext)
{
	if (filename && ext && ft_strlen(filename) >= ft_strlen(ext))
		return (!ft_strcmp(ft_strchr(filename, '\0') - ft_strlen(ext), ext));
	else
		return (false);
}

inline int8_t	get_byte(t_vm *vm, int32_t pc, int32_t step)
{
	return (vm->arena[calc_addr(pc + step)]);
}

void			visual_interface_indexation(t_vm *vm,
				t_cursor *cursor, int32_t addr, int32_t size)
{
	uint32_t	value;

	value = 0;
	if (cursor->player >= MIN_PLAYER_ID && cursor->player <= vm->players_num)
		value = cursor->player;
	if (value)
	{
		while (size)
		{
			vm->vs->map[calc_addr(addr + size - 1)].value = value;
			vm->vs->map[calc_addr(addr + size - 1)].time_to_wait =
					CYCLE_TO_WAIT;
			size--;
		}
	}
}
