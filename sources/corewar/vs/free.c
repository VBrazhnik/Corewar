/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:33:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 18:31:31 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"

void	free_vs(t_vm *vm)
{
	delwin(vm->vs->win_info);
	delwin(vm->vs->win_arena);
	delwin(vm->vs->win_help);
	ft_memdel((void *)&vm->vs);
	endwin();
	exit(0);
}
