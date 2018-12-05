/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:01:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/05 21:31:22 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_players(t_player **players, size_t players_num)
{
	int		id;

	id = 1;
	while (id <= players_num)
	{
		ft_strdel(&(players[INDEX(id)]->name));
		ft_strdel(&(players[INDEX(id)]->comment));
		ft_memdel((void **)&(players[INDEX(id)]->code));
		ft_memdel((void **)&players[INDEX(id)]);
		id++;
	}
}
