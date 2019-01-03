/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:39:07 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/01/03 06:35:29 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "corewar.h"
#include <stdlib.h>

void		print_intro(t_player **players, int32_t players_num)
{
	int32_t id;

	id = 1;
	ft_printf("Introducing contestants...\n");
	while (id <= players_num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
												id,
												players[INDEX(id)]->code_size,
												players[INDEX(id)]->name,
												players[INDEX(id)]->comment);
		id++;
	}
}

inline void	print_last_alive(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
													FT_ABS(vm->last_alive->id),
													vm->last_alive->name);
}

void		print_arena(uint8_t *arena, int print_mode)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.4p : ", i);
		j = 0;
		while (j < print_mode)
		{
			ft_printf("%.2x ", arena[i + j]);
			j++;
		}
		ft_printf("\n");
		i += print_mode;
	}
}

void		print_help(void)
{
	ft_printf("Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l"\
							" <num>] [-v] [-n <num>] <champion.cor> <...>\n");
	ft_printf("    %-11s : Print output from \"aff\" (Default is off)\n", "-a");
	ft_printf("    %-11s : Dump memory (32 octets per line)"\
							" after <num> cycles and exit\n", "-dump <num>");
	ft_printf("    %-11s : Dump memory (64 octets per line)"\
							" after <num> cycles and exit\n", "-d    <num>");
	ft_printf("    %-11s : Run <num> cycles, dump memory (32 octets per line),"\
							" pause and repeat\n", "-show <num>");
	ft_printf("    %-11s : Run <num> cycles, dump memory (64 octets per line),"\
							" pause and repeat\n", "-s    <num>");
	ft_printf("    %-11s : Log levels\n", "-l    <num>");
	ft_printf("            %9s : Show lives\n", "1 ");
	ft_printf("            %9s : Show cycles\n", "2 ");
	ft_printf("            %9s : Show operations\n", "4 ");
	ft_printf("            %9s : Show deaths\n", "8 ");
	ft_printf("            %9s : Show PC movements\n", "16");
	ft_printf("    %-11s : Run visualizer\n", "-v");
	ft_printf("    %-11s : Set <num> of the next player\n", "-n    <num>");
	exit(0);
}
