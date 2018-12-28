/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_corewar_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:58:16 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/28 19:13:17 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error.h"

static void	add_player(t_player **list, t_player *new)
{
	t_player *current;

	if (list && new)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
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
	int32_t id;

	id = 0;
	if (*argc >= 3 && !ft_strcmp(**argv, "-n"))
	{
		if (!ft_isint(*(*argv + 1), true)
			|| (id = ft_atoi(*(*argv + 1))) < 1
			|| id > MAX_PLAYERS
			|| find_player(*list, id)
			|| !is_filename(*(*argv + 2), ".cor"))
			print_help();
		add_player(list, parse_champion(*(*argv + 2), id));
		vm->players_num++;
		(*argc) -= 3;
		(*argv) += 3;
	}
	else if (is_filename(**argv, ".cor"))
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
	player = list;
	while (player)
	{
		if (player->id == 0)
		{
			while (find_player(list, id))
				id++;
			player->id = id;
		}
		player = player->next;
	}
}

static void	set_players(t_vm *vm, t_player *list)
{
	int32_t id;

	id = 1;
	update_players_ids(list);
	while (id <= vm->players_num)
	{
		if (!(vm->players[INDEX(id)] = find_player(list, id)))
			print_help();
		id++;
	}
	vm->last_alive = vm->players[INDEX(vm->players_num)];
}

void		parse_corewar_args(int argc, char **argv, t_vm *vm)
{
	t_player *list;

	list = NULL;
	argc--;
	argv++;
	while (argc >= 1)
	{
		if (!ft_strcmp(*argv, "-v"))
			parse_vs_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-dump") || !ft_strcmp(*argv, "-d"))
			parse_dump_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-show") || !ft_strcmp(*argv, "-s"))
			parse_show_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-a"))
			parse_aff_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-l"))
			parse_log_flag(&argc, &argv, vm);
		else if (!ft_strcmp(*argv, "-n") || is_filename(*argv, ".cor"))
			parse_champion_filename(&argc, &argv, vm, &list);
		else
			print_help();
	}
	if (vm->players_num < 1 || vm->players_num > MAX_PLAYERS)
		terminate(ERR_PLAYERS_NUM);
	set_players(vm, list);
}
