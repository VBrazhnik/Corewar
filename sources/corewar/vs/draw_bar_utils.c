/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widget_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:11:00 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/25 02:44:03 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	store_players_lives(t_vm *vm)
{
	int32_t i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->vs->players_lives[i] = vm->players[i]->lives_num;
		i++;
	}
}
