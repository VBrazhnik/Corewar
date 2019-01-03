/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:23:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 16:11:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	play_victory_sound(t_vm *vm)
{
	if (vm->vs->sounds)
	{
		system("pkill afplay");
		system("afplay sounds/victory.mp3 &> /dev/null &");
	}
}

void	play_death_sound(t_vm *vm)
{
	if (vm->vs->sounds)
	{
		system("pkill afplay");
		system("afplay sounds/blaster.mp3 &> /dev/null &");
	}
}
