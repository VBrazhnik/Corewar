/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_corewar_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:22:56 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 18:22:56 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_vs.h"

void	parse_vs_flag(int *argc, char ***argv, t_vm *vm)
{
	vm->vs = init_vs();
	(*argc)--;
	(*argv)++;
}

void	parse_dump_flag(int *argc, char ***argv, t_vm *vm)
{
	if (!vm->dump_print_mode && *argc >= 2 && ft_isint(*(*argv + 1), true))
	{
		if ((vm->dump_cycle = ft_atoi(*(*argv + 1))) < 0)
			vm->dump_cycle = -1;
		if (!ft_strcmp(**argv, "-d"))
			vm->dump_print_mode = 64;
		else
			vm->dump_print_mode = 32;
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		print_help();
}

void	parse_show_flag(int *argc, char ***argv, t_vm *vm)
{
	if (!vm->show_print_mode && *argc >= 2 && ft_isint(*(*argv + 1), true))
	{
		if ((vm->show_cycle = ft_atoi(*(*argv + 1))) <= 0)
			vm->show_cycle = -1;
		if (!ft_strcmp(**argv, "-s"))
			vm->show_print_mode = 64;
		else
			vm->show_print_mode = 32;
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
	if (*argc >= 2 && ft_isint(*(*argv + 1), true))
	{
		vm->log = ft_atoi(*(*argv + 1));
		(*argc) -= 2;
		(*argv) += 2;
	}
	else
		print_help();
}
