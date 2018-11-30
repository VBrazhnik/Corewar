/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:39:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/11/30 19:40:04 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "corewar.h"
#include <stdlib.h>

void		print_intro(t_player **players)
{
	int		i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		if (players[i])
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
														i + 1,
														players[i]->code_size,
														players[i]->name,
														players[i]->comment);
		i++;
	}
}

inline void	print_last_alive(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
													FT_ABS(vm->last_alive->id),
													vm->last_alive->name);
}

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
}

void		print_help(void)
{
	ft_printf("Usage: ./corewar [-a -d <num> -s <num> -l <num>] [-v]"\
										" [-n <num>] <champion.cor> <...>\n");
	ft_printf("\t%-10s : Print output from \"aff\" (Default is off)\n", "-a");
	ft_printf("\t%-10s : Dump memory after <num> cycles and exit\n",
																	"-d <num>");
	ft_printf("\t%-10s : Run <num> cycles, dump memory, pause and repeat\n",
																	"-s <num>");
	ft_printf("\t%-10s : Log levels\n", "-l <num>");
	ft_printf("\t\t%9s : Show lives\n", "- 1 ");
	ft_printf("\t\t%9s : Show cycles\n", "- 2 ");
	ft_printf("\t\t%9s : Show operations\n", "- 4 ");
	ft_printf("\t\t%9s : Show deaths\n", "- 8 ");
	ft_printf("\t\t%9s : Show PC movements\n", "- 16");
	ft_printf("\t%-10s : Run visualizer\n", "-v");
	ft_printf("\t%-10s : Set <num> to player. 1 >= <num> <= MAX_PLAYERS\n",
																"-n <num>");
	exit(0);
}
