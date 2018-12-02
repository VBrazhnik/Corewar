/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bot_name_comm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:02:38 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:02:40 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_bot_comm(t_val *assm)
{
	int		i;
	int		tmpi;

	i = ft_skip_whitespaces(assm->str, 0);
	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(COMMENT_CMD_STRING))))
		local_error(assm, "Malloc error saving champion's comment)\n", 0);
	if ((tmpi = ft_strcmpi(assm->r_str, COMMENT_CMD_STRING)) != -1)
		local_error(assm, "Comment command error\n", tmpi + 1);
	ft_strdel(&assm->r_str);
	i = ft_skip_whitespaces(assm->str, ft_strlen(COMMENT_CMD_STRING) + i);
	if (assm->str[i++] != '\"')
		local_error(assm, "Comment error: No opening quotation mark\n", i);
	while (assm->str[i] && assm->str[i] != '\"'
		&& assm->i < PROG_NAME_LENGTH + COMMENT_LENGTH + 12)
		assm->data[assm->i++] = assm->str[i++];
	if (assm->str[i] != '\"')
		local_error(assm, "Comment error: No closing quotation mark\n", i + 1);
	check_comm(assm, i);
	while (assm->i < NAME_COMM_LENGTH)
		assm->data[assm->i++] = 0;
}

void		check_bot_name(t_val *assm)
{
	int		i;
	int		tmpi;

	i = ft_skip_whitespaces(assm->str, 0);
	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(NAME_CMD_STRING))))
		local_error(assm, "Malloc error saving champion's name)\n", 0);
	if ((tmpi = ft_strcmpi(assm->r_str, NAME_CMD_STRING)) != -1)
		local_error(assm, "Name command error\n", tmpi + 1);
	ft_strdel(&assm->r_str);
	i = ft_skip_whitespaces(assm->str, ft_strlen(NAME_CMD_STRING) + i);
	if (assm->str[i++] != '\"')
		local_error(assm, "Name error: No opening quotation mark\n", i);
	while (assm->str[i] && assm->str[i] != '\"' && assm->i
			< PROG_NAME_LENGTH + 4)
		assm->data[assm->i++] = assm->str[i++];
	if (assm->str[i] != '\"')
		local_error(assm, "Name error: No closing quotation mark\n", i + 1);
	check_comm(assm, i);
	while (assm->i < PROG_NAME_LENGTH + 12)
		assm->data[assm->i++] = 0;
}

void		clean_comments_h(t_val *assm)
{
	int		i;
	int		total;

	if (assm->str && assm->str[0])
	{
		i = 0;
		total = ft_strlen(assm->str);
		while ((i <= total) && ft_iswhitespace(assm->str[i]))
			i++;
		if (assm->str[i] == COMMENT_CHAR || assm->str[i] == ALT_COMMENT_CHAR)
		{
			assm->r_str = assm->str;
			if (!(assm->str = ft_strsub(assm->str, 0, i)))
				local_error(assm, "Malloc error cleaning comments\n", 0);
			ft_strdel(&assm->r_str);
		}
		i = ft_strlen(assm->str) - 1;
		while (i >= 0 && ft_iswhitespace(assm->str[i]))
			i--;
		assm->r_str = assm->str;
		if (!(assm->str = ft_strsub(assm->str, 0, i + 1)))
			local_error(assm, "Malloc error cleaning comments\n", 0);
		ft_strdel(&assm->r_str);
	}
}

/*
**  3-2-1-0 = 4
**	assm->data[0] = (char)0;
**	assm->data[1] = (char)234;
**	assm->data[2] = (char)131;
**	assm->data[3] = (char)243;
*/

void		place_magic_header(t_val *assm)
{
	int		i;
	int		magic;

	if (!(assm->data = (char*)malloc(sizeof(char) *
			(NAME_COMM_LENGTH + CHAMP_MAX_SIZE))))
		print_error(assm, "Malloc error (creating header)\n");
	magic = COREWAR_EXEC_MAGIC;
	i = 3;
	while (i >= 0)
	{
		assm->data[i] = (magic % 256);
		magic = magic / 256;
		i--;
	}
}

void		read_bot_name_comm(t_val *assm, int i, int ret)
{
	place_magic_header(assm);
	while (ret && i < 2)
	{
		if ((ret = get_next_line(assm->fd, &assm->str)) == -1)
			print_error(assm, "Error when reading file\n");
		assm->pos_y++;
		clean_comments_h(assm);
		if (ret && assm->str[0])
		{
			if (i == 0 && ft_strlen(assm->str) > ft_strlen(NAME_CMD_STRING))
				check_bot_name(assm);
			else if (i == 0)
				local_error(assm, "Name command error\n", 0);
			else if (i == 1 && ft_strlen(assm->str) >
				ft_strlen(COMMENT_CMD_STRING))
				check_bot_comm(assm);
			else if (i == 1)
				local_error(assm, "Comment command error\n", 0);
			i++;
		}
		if (assm->str)
			ft_strdel(&assm->str);
	}
	if (i != 2)
		local_error(assm, "Invalid bot header\n", 0);
}
