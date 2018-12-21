/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:33:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/20 22:33:16 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs_lib.h"

void	free_vs(t_vm *vm)
{
	delwin(vm->vs->win_info);
	delwin(vm->vs->win_arena);
	ft_memdel((void *)&vm->vs);
	endwin();
	exit(0);
}
