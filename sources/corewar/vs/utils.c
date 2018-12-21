/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:09:01 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 23:10:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

clock_t			calc_time_delay(t_vm *vm)
{
	clock_t		time;

	time = (vm->vs->time + CLOCKS_PER_SEC / vm->vs->speed);
	return (time);
}

char			*clear_name(char *name)
{
	size_t		i;

	i = 0;
	if (!name)
		return (NULL);
	while (name[i])
	{
		if (name[i] == '\n')
			name[i] = ' ';
		i++;
	}
	return (name);
}

void			handle_buttons(t_vm *vm)
{
	if ((vm)->vs->control_button == MUSIC)
		(vm)->vs->sounds = !(vm)->vs->sounds;
	else if ((vm)->vs->control_button == DISPLAY_HELP)
		(vm)->vs->display_help = !(vm)->vs->display_help;
	else if (vm->vs->control_button == SPEED_UP_1)
		vm->vs->speed++;
	else if (vm->vs->control_button == SPEED_UP_10)
		vm->vs->speed += 10;
	else if (vm->vs->control_button == SPEED_UP_100)
		vm->vs->speed += 100;
	else if (vm->vs->control_button == SPEED_DOWN_1)
		vm->vs->speed--;
	else if (vm->vs->control_button == SPEED_DOWN_10)
		vm->vs->speed -= 10;
	else if (vm->vs->control_button == SPEED_DOWN_100)
		vm->vs->speed -= 100;
	else if (vm->vs->control_button == SPEED_DEFAULT)
		vm->vs->speed = DEFAULT_SPEED;
	else if (vm->vs->speed <= 1)
		vm->vs->speed = 1;
	else if (vm->vs->speed > 1000)
		vm->vs->speed = 1000;
}

void			vs_init_refresh(t_vm *vm)
{
	fill_map(vm);
	drawing_main_info(vm);
	draw_border((vm)->vs->win_arena);
	wrefresh(vm->vs->win_info);
	wrefresh(vm->vs->win_arena);
	wrefresh(vm->vs->win_help);
}
