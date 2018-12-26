/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:45:54 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/26 12:40:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void		init_colors(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(GRAY, COLOR_GRAY, 0);
	init_pair(GREEN, COLOR_GREEN, 0);
	init_pair(YELLOW, COLOR_YELLOW, 0);
	init_pair(RED, COLOR_RED, 0);
	init_pair(CYAN, COLOR_CYAN, 0);
	init_pair(GRAY_CURSOR, COLOR_BLACK, COLOR_GRAY);
	init_pair(GREEN_CURSOR, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW_CURSOR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(RED_CURSOR, COLOR_BLACK, COLOR_RED);
	init_pair(CYAN_CURSOR, COLOR_BLACK, COLOR_CYAN);
	init_pair(LIVE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(LIVE_YELLOW, COLOR_WHITE, COLOR_YELLOW);
	init_pair(LIVE_RED, COLOR_WHITE, COLOR_RED);
	init_pair(LIVE_CYAN, COLOR_WHITE, COLOR_CYAN);
}

static int	get_live_color(t_player *player)
{
	int32_t index;

	index = ((player->id - 1) % MAX_PLAYER_ID) + 1;
	if (index == MIN_PLAYER_ID)
		return (COLOR_PAIR(LIVE_GREEN) | A_BOLD);
	else if (index == MIN_PLAYER_ID + 1)
		return (COLOR_PAIR(LIVE_YELLOW) | A_BOLD);
	else if (index == MIN_PLAYER_ID + 2)
		return (COLOR_PAIR(LIVE_RED) | A_BOLD);
	else
		return (COLOR_PAIR(LIVE_CYAN) | A_BOLD);
}

int			get_attribute(t_vm *vm, t_attr *attribute, ssize_t cycles)
{
	if (cycles != vm->cycles
		&& vm->cycles_to_die > 0
		&& attribute->wait_cycles_live > 0)
		attribute->wait_cycles_live--;
	if (cycles != vm->cycles
		&& vm->cycles_to_die > 0
		&& attribute->wait_cycles_store > 0)
		attribute->wait_cycles_store--;
	if (attribute->wait_cycles_live)
		return (get_live_color(attribute->player_live));
	else if (attribute->wait_cycles_store)
		return (g_colors_players[attribute->index] | A_BOLD);
	else
		return (g_colors_players[attribute->index]);
}
