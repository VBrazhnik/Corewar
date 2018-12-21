/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 23:11:24 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/21 15:58:08 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void		vs_exec(t_vm *vm)
{
	exec_cycle(vm);
	if (vm->cycles_to_die == vm->cycles_after_check)
	{
		fill_last_live_arr(&vm);
		cycles_to_die_check(vm);
		play_sounds(vm);
		vm->vs->cariage_quant_delta = vm->cursors_num;
		vm->vs->total_lives_in_last_per = vm->vs->total_lives_in_curr_per;
	}
	if (vm->cycles_to_die <= 0 || !vm->cursors_num)
		vm->vs->is_run = false;
	vm->vs->total_lives_in_curr_per = total_lives_in_curr_period(vm);
}

void		controller(t_vm *vm)
{
	initial_drawing(vm);
	while (((vm)->vs->control_button = getch()) != ESC)
	{
		handle_buttons(vm);
		draw_status(vm);
		if ((vm)->vs->control_button == PASS_ONE_CYCLE)
		{
			if ((vm)->cursors_num)
				vs_exec(vm);
			(vm)->vs->control_button = 0;
		}
		if ((vm)->vs->is_run && ((vm)->vs->time_delay =
				(clock() >= calc_time_delay(vm))))
		{
			(vm)->vs->time = clock();
			if ((vm)->cursors_num)
				vs_exec(vm);
		}
		vs_init_refresh(vm);
	}
	free_vs(vm);
}
