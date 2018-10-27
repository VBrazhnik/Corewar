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
#include <stdlib.h>

static void	ft_putdigit_fd(uintmax_t digit, t_bool upper, int fd)
{
	if (digit < 10)
		ft_putchar_fd(digit + '0', fd);
	else
		ft_putchar_fd((char)(((upper) ? 'A' : 'a') + (digit - 10)), fd);
}

static void	print_hex(uint8_t number)
{
	ft_putdigit_fd(number / 16, false, 1);
	ft_putdigit_fd(number % 16, false, 1);
}

void		print_arena(uint8_t *arena)
{
	int i;
	int j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			print_hex(arena[i * 64 + j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		print_help(void)
{
	ft_putendl("Help!");
	exit(0);
}
