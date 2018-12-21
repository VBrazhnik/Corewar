/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vs_lib.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:38:48 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/21 15:58:30 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VS_LIB_H
#define COREWAR_VS_LIB_H

# include "corewar.h"
# include "corewar_vs.h"
# include "corewar_error.h"
# include "op.h"

void					pre_draw_cursors(t_vm *vm);

void					draw_status(t_vm *vm);

void					draw_aff(t_vm *vm);

void					drawing_final_info(t_vm *vm);

uint32_t				check_attributes(t_vm *vm, t_map *attribute);

void					sound_player_status(t_vm *vm);

char					*clear_name(char *name);

void					print_instructions(t_vm *vm);

void					fill_id_map(t_vm *vm);

void					drawing_main_info(t_vm *vm);

clock_t					calc_time_delay(t_vm *vm);

void					handle_buttons(t_vm *vm);

void					colors(void);

void					draw_help(t_vm *vm);

void					draw_winner(t_vm *vm);

void					free_vs(t_vm *vm);

void					fill_last_live_arr(t_vm **vm);

void					draw_live_breakdown(t_vm *vm, size_t total_live_in_per,
											char *period);

void					fill_map(t_vm *vm);

void					visual_interface_indexation(t_vm *vm, t_cursor *cursor, int32_t addr, int32_t size);

void					initial_drawing(t_vm *vm);

t_vs					*init_vs(void);

void					draw_border(WINDOW *wnd);

void					draw_cursor(t_vm *vm, t_cursor *cursor);

void					vs_init_refresh(t_vm *vm);

void					clear_cursor(t_vm *vm, t_cursor *cursor);

void					controller(t_vm *vm);

void					drawing_players_info(t_vm *vm);

int32_t					calc_live_breakdown(double curr_lives, size_t total_lives);

size_t					total_lives_in_curr_period(t_vm  *vm);

void					play_sounds(t_vm *vm);

void					play_winner(t_vm *vm);

#endif
