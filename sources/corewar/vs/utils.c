/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:09:01 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 20:10:21 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

clock_t	calc_time_delay(t_vm *vm)
{
	return (vm->vs->time + CLOCKS_PER_SEC / vm->vs->speed);
}

void	clear_name(char *name)
{
	size_t i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '\n' || name[i] == '\t' || name[i] == '\v')
			name[i] = ' ';
		i++;
	}
}
