/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:33:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/26 12:25:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	free_vs(t_vs **vs)
{
	delwin((*vs)->win_info);
	delwin((*vs)->win_arena);
	delwin((*vs)->win_help);
	ft_memdel((void *)vs);
	endwin();
}
