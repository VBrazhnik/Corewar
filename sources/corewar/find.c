/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:06:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/26 17:06:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player	*find_player(t_player *list, int32_t id)
{
	t_player *player;

	player = NULL;
	if (id >= 1 && id <= MAX_PLAYERS)
	{
		player = list;
		while (player)
		{
			if (player->id == id)
				return (player);
			player = player->next;
		}
	}
	return (player);
}
