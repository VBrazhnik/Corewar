/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:50:41 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/25 19:50:42 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_vs_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->vs = init_vs();
	(*argc)--;
	(*argv)++;
}

void	parse_dump_flag(int *argc, char ***argv, t_vm *vm)
{
	if (*argc >= 2 && ft_isint(*(*argv + 1), true)
		&& (vm->dump = ft_atoi(*(*argv + 1))) >= 0)
	{
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		print_help();
}

void	parse_aff_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->display_aff = true;
	(*argc)--;
	(*argv)++;
}

void	parse_log_flag(int *argc, char ***argv, t_vm *vm)
{
	int	level;

	if (*argc >= 2 && ft_isint(*(*argv + 1), true)
		&& (level = ft_atoi(*(*argv + 1))) >= 0)
	{
		level = (level > 31) ? 31 : level;
		vm->log |= level;
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		print_help();
}