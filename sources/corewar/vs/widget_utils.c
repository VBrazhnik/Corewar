/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:11:00 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 17:08:06 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

int32_t		calc_percent(double curr_lives, size_t total_lives)
{
	double value;

	if (!total_lives)
		return (0);
	else if (curr_lives)
	{
		value = ((curr_lives / total_lives) * WIDGET_LEN);
		if ((value - (int32_t)(value)) >= 0.5)
			value++;
		return ((int32_t)value);
	}
	return (0);
}

void		store_players_lives(t_vm *vm)
{
	int32_t i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->vs->players_lives[i] = vm->players[i]->lives_num;
		i++;
	}
}

size_t		calc_players_lives(t_vm *vm)
{
	int32_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (i < vm->players_num)
		sum += vm->players[i++]->lives_num;
	return (sum);
}
