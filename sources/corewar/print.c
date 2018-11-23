/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:39:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/25 18:39:07 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <includes/corewar.h>

void		print_arena(uint8_t *arena)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		ft_printf("%.4p : ", i * 64);
		j = 0;
		while (j < 64)
		{
			ft_printf("%.2x ", arena[i * 64 + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	exit(0);
}

void		print_help(void)
{
	ft_putendl("Help!");
	exit(0);
}
