/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:49:18 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/24 17:42:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_vs.h"

static void	handle_buttons(t_vm *vm)
{
	if (vm->vs->button == MUSIC)
		vm->vs->sounds = !(vm->vs->sounds);
	else if (vm->vs->button == DISPLAY_HELP)
		vm->vs->display_help = !(vm->vs->display_help);
	else if (vm->vs->button == SPEED_UP_1)
		vm->vs->speed++;
	else if (vm->vs->button == SPEED_UP_10)
		vm->vs->speed += 10;
	else if (vm->vs->button == SPEED_UP_100)
		vm->vs->speed += 100;
	else if (vm->vs->button == SPEED_DOWN_1)
		vm->vs->speed--;
	else if (vm->vs->button == SPEED_DOWN_10)
		vm->vs->speed -= 10;
	else if (vm->vs->button == SPEED_DOWN_100)
		vm->vs->speed -= 100;
	else if (vm->vs->button == SPEED_DEFAULT)
		vm->vs->speed = DEFAULT_SPEED;
	if (vm->vs->speed < 1)
		vm->vs->speed = 1;
	if (vm->vs->speed > 1000)
		vm->vs->speed = 1000;
}

static void	exec_cycle_vs(t_vm *vm)
{
	size_t cursors_num;

	if (vm->cursors_num)
	{
		exec_cycle(vm);
		if (vm->cycles_to_die <= 0)
			delete_cursors(vm);
		if (vm->cycles_to_die == vm->cycles_after_check)
		{
			store_players_lives(vm);
			cursors_num = vm->cursors_num;
			cycles_to_die_check(vm);
			if (cursors_num != vm->cursors_num)
				play_death_sound(vm);
			vm->vs->total_lives_in_last_per = vm->vs->total_lives_in_curr_per;
		}
		if (!vm->cursors_num)
		{
			play_winner_sound(vm);
			vm->vs->is_run = false;
		}
		vm->vs->total_lives_in_curr_per = calc_players_lives(vm);
	}
}

static void	pass_one_cycle(t_vm *vm)
{
	vm->vs->is_run = true;
	vm->vs->time_delay = true;
	exec_cycle_vs(vm);
	draw(vm);
	vm->vs->time_delay = false;
	vm->vs->is_run = false;
}

void		exec_vs(t_vm *vm)
{
	int32_t id;

	id = 1;
	while (id <= vm->players_num)
		clear_name(vm->players[INDEX(id++)]->name);
	configure_vs(vm);
	while ((vm->vs->button = getch()) != ESC)
	{
		handle_buttons(vm);
		draw_exec_status(vm);
		if (vm->vs->button == PASS_ONE_CYCLE)
			pass_one_cycle(vm);
		else if (vm->vs->is_run
				&& (vm->vs->time_delay = (clock() >= calc_time_delay(vm))))
		{
			vm->vs->time = clock();
			exec_cycle_vs(vm);
		}
		draw(vm);
	}
	free_vs(vm);
}
