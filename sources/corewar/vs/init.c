/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:48:48 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/26 16:31:02 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"
#include "corewar_error.h"

t_vs	*init_vs(void)
{
	t_vs *vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		terminate(ERR_VS_INIT);
	vs->is_running = false;
	vs->speed = DEFAULT_SPEED;
	vs->win_arena = NULL;
	vs->win_info = NULL;
	vs->win_help = NULL;
	vs->cursor_pos = 0;
	vs->button = 0;
	vs->time = 0;
	vs->aff_symbol = 0;
	vs->aff_player = NULL;
	vs->sounds = false;
	vs->display_help = false;
	return (vs);
}
