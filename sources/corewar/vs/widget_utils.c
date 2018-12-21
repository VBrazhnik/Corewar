/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:11:00 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/21 16:24:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

int32_t		calc_live_breakdown(double curr_lives, size_t total_lives)
{
	double	value;

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

void		fill_last_live_arr(t_vm **vm)
{
	int32_t	i;

	i = 0;
	while (i < (*vm)->players_num)
	{
		(*vm)->vs->last_per_live[i] = (*vm)->players[i]->lives_num;
		i++;
	}
}

size_t		total_lives_in_curr_period(t_vm *vm)
{
	int32_t	i;
	size_t	total_amount;

	i = 0;
	total_amount = 0;
	while (i < vm->players_num)
	{
		total_amount += vm->players[i]->lives_num;
		i++;
	}
	return (total_amount);
}
