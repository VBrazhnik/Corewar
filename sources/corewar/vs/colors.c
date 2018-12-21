/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 21:45:54 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 22:33:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void		colors(void)
{
	init_color(COLOR_GRAY, 355, 355, 355);
	init_pair(GREEN_PLAYER, COLOR_GREEN, 0);
	init_pair(BLUE_PLAYER, COLOR_BLUE, 0);
	init_pair(RED_PLAYER, COLOR_RED, 0);
	init_pair(CYAN_PLAYER, COLOR_CYAN, 0);
	init_pair(GREEN_CURSOR, COLOR_GRAY, COLOR_GREEN);
	init_pair(BLUE_CURSOR, COLOR_GRAY, COLOR_BLUE);
	init_pair(RED_CURSOR, COLOR_GRAY, COLOR_RED);
	init_pair(CYAN_CURSOR, COLOR_GRAY, COLOR_CYAN);
	init_pair(LIVE_PAIR_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(LIVE_PAIR_BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(LIVE_PAIR_RED, COLOR_WHITE, COLOR_RED);
	init_pair(LIVE_PAIR_CYAN, COLOR_WHITE, COLOR_CYAN);
	init_pair(GRAY_PLAYER, COLOR_GRAY, 0);
	init_pair(GRAY_CURSOR, COLOR_BLACK, COLOR_GRAY);
}

uint32_t	live_announce_colors(t_map *attribute)
{
	if (attribute->value == MIN_PLAYER_ID &&
	attribute->time_to_wait_live)
		return (COLOR_PAIR(LIVE_PAIR_GREEN) | A_BOLD);
	else if (attribute->value == MIN_PLAYER_ID + 1 &&
	attribute->time_to_wait_live)
		return (COLOR_PAIR(LIVE_PAIR_BLUE) | A_BOLD);
	else if (attribute->value == MIN_PLAYER_ID + 2 &&
	attribute->time_to_wait_live)
		return (COLOR_PAIR(LIVE_PAIR_RED) | A_BOLD);
	else if (attribute->value == MIN_PLAYER_ID + 3 &&
	attribute->time_to_wait_live)
		return (COLOR_PAIR(LIVE_PAIR_CYAN) | A_BOLD);
	return (g_colors_players[attribute->value]);
}

uint32_t	check_attributes(t_vm *vm, t_map *attribute)
{
	if (attribute->value)
	{
		if (attribute->time_to_wait_live)
		{
			if (vm->vs->is_run && vm->vs->time_delay)
				attribute->time_to_wait_live--;
			return (live_announce_colors(attribute));
		}
		if (attribute->time_to_wait && !attribute->time_to_wait_live)
		{
			if (vm->vs->is_run && vm->vs->time_delay)
				attribute->time_to_wait--;
			return (g_colors_players[attribute->value] | A_BOLD);
		}
		return (g_colors_players[attribute->value]);
	}
	return (g_colors_players[attribute->value]);
}
