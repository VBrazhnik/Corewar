/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:02:48 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:02:50 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		operations_small(t_val *assm, int i)
{
	if (!ft_strcmp(assm->r_str, "st"))
		check_st(assm, i);
	else if (!ft_strcmp(assm->r_str, "sti"))
		check_sti(assm, i);
	else if (!ft_strcmp(assm->r_str, "sub"))
		check_sub(assm, i);
	else if (!ft_strcmp(assm->r_str, "xor"))
		check_xor(assm, i);
	else if (!ft_strcmp(assm->r_str, "zjmp"))
		check_zjmp(assm, i);
	else
		local_error(assm, "Unknown instruction\n", i);
}

void		operations_big(t_val *assm, int i)
{
	if (!ft_strcmp(assm->r_str, "add"))
		check_add(assm, i);
	else if (!ft_strcmp(assm->r_str, "aff"))
		check_aff(assm, i);
	else if (!ft_strcmp(assm->r_str, "and"))
		check_and(assm, i);
	else if (!ft_strcmp(assm->r_str, "fork"))
		check_fork(assm, i);
	else if (!ft_strcmp(assm->r_str, "ld"))
		check_ld(assm, i);
	else if (!ft_strcmp(assm->r_str, "ldi"))
		check_ldi(assm, i);
	else if (!ft_strcmp(assm->r_str, "lfork"))
		check_lfork(assm, i);
	else if (!ft_strcmp(assm->r_str, "live"))
		check_live(assm, i);
	else if (!ft_strcmp(assm->r_str, "lld"))
		check_lld(assm, i);
	else if (!ft_strcmp(assm->r_str, "lldi"))
		check_lldi(assm, i);
	else if (!ft_strcmp(assm->r_str, "or"))
		check_or(assm, i);
	else
		operations_small(assm, i);
}

void		parse_operation(t_val *assm, int i)
{
	int		pos;

	pos = ft_skip_whitespaces(assm->str, i);
	i = pos;
	while (assm->str[i] && !ft_iswhitespace(assm->str[i]))
		i++;
	if (!(assm->r_str = ft_strsub(assm->str, pos, i - pos)))
		print_error(assm, "Malloc error (reading instruction)\n");
	operations_big(assm, i);
	if (assm->r_str)
		ft_strdel(&assm->r_str);
}

/*
** Clean instruction from comment
*/

void		clean_comments_i(t_val *assm)
{
	int		i;
	int		j;

	if (assm->str && assm->str[0])
	{
		if (((i = ft_strchri(assm->str, COMMENT_CHAR)) != -1)
		|| (j = ft_strchri(assm->str, ALT_COMMENT_CHAR)) != -1)
		{
			(i != -1) ? j = ft_strchri(assm->str, ALT_COMMENT_CHAR) : 0;
			(i == -1) ? i = j : 0;
			((j != -1 && i != -1) && j < i) ? i = j : 0;
			assm->r_str = assm->str;
			if (!(assm->str = ft_strsub(assm->str, 0, i)))
				print_error(assm, "Malloc error (cleaning line)\n");
			ft_strdel(&assm->r_str);
		}
		i = ft_strlen(assm->str) - 1;
		while (i >= 0 && ft_iswhitespace(assm->str[i]))
			i--;
		assm->r_str = assm->str;
		if (!(assm->str = ft_strsub(assm->str, 0, i + 1)))
			print_error(assm, "Malloc error (cleaning line)\n");
		ft_strdel(&assm->r_str);
	}
}

void		read_bot_op(t_val *assm)
{
	int		tmp_pos;
	int		ret;

	while ((ret = get_next_line(assm->fd, &assm->str)) > 0)
	{
		clean_comments_i(assm);
		assm->pos_y++;
		if (assm->str[0])
		{
			tmp_pos = read_label(assm, 0, assm->i, 0);
			if (assm->str[tmp_pos])
				parse_operation(assm, tmp_pos);
		}
		ft_strdel(&assm->str);
		if (assm->i - NAME_COMM_LENGTH > CHAMP_MAX_SIZE)
			print_error(assm, "Max file size exceeded\n");
	}
	if (assm->i - NAME_COMM_LENGTH <= 0)
		print_error(assm, "No instructions to write\n");
	if (ret == -1)
		print_error(assm, "Error when reading file\n");
	tmp_pos = assm->i;
	place_size(assm);
	place_labels(assm);
	assm->i = tmp_pos;
}
