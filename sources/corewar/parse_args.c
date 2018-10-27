/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:06:23 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/25 17:06:24 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -v                  — visualize
** -d N                — dump memory after N cycles then exit
** -a                  — display output of aff operator
** -l <num>            — write logs. <num> defines log level.
** -n <num> <champion> — set as player's number value of <num>
*/

#include "corewar.h"
#include "corewar_error_msg.h"

static void	add_player(t_player **list, t_player *new)
{
	t_player	*iterator;

	if (list && new)
	{
		if (*list)
		{
			iterator = *list;
			while (iterator->next)
				iterator = iterator->next;
			iterator->next = new;
		}
		else
			*list = new;
	}
}

static void	parse_champion_filename(int *argc,
									char ***argv,
									t_vm *vm,
									t_player **list)
{
	int		id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!ft_isint(*(*argv + 1), true) ||
			(id = ft_atoi(*(*argv + 1))) < 1 ||
			id > MAX_PLAYERS ||
			find_player(*list, id) ||
			!is_filename(*(*argv + 2)))
			print_help();
		add_player(list, parse_champion(*(*argv + 2), id));
		vm->players_num++;
		(*argc) -= 3;
		(*argv) += 3;
	}
	else if (is_filename(**argv))
	{
		add_player(list, parse_champion(**argv, id));
		vm->players_num++;
		(*argc)--;
		(*argv)++;
	}
	else
		print_help();
}

static void	update_players_ids(t_player *list)
{
	t_player	*player;
	int32_t		id;

	id = 1;
	while (id <= MAX_PLAYERS)
	{
		player = list;
		if (!find_player(list, id))
			while (player)
			{
				if (player->id == 0)
				{
					player->id = id;
					break ;
				}
				player = player->next;
			}
		id++;
	}
}

static void	set_players(t_vm *vm, t_player *list)
{
	int32_t id;

	id = 1;
	update_players_ids(list);
	while (id <= MAX_PLAYERS)
	{
		vm->players[id - 1] = find_player(list, id);
		id++;
	}
}

void		parse_args(int argc, char **argv, t_vm *vm)
{
	t_player *list;

	list = NULL;
	argc--;
	argv++;
	while (argc >= 1)
	{
		if (!ft_strcmp(*argv, "-v"))
			parse_vs_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-d"))
			parse_dump_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-a"))
			parse_aff_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-l"))
			parse_log_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-n") ||
			is_filename(*argv))
			parse_champion_filename(&argc, &argv, vm, &list);
		else
			print_help();
		if (vm->players_num > MAX_PLAYERS)
			terminate(ERR_PLAYERS_NUM);
	}
	set_players(vm, list);
}
