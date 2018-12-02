/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:00:17 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:00:18 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>

int			get_size(int dir_size, int type, int name_elem)
{
	if (name_elem == 1)
	{
		if (type == IND_CODE)
			return (0);
		return (1);
	}
	if (type == REG_CODE)
		return (1);
	else if (type == DIR_CODE)
		return (dir_size);
	return (2);
}

int			get_type(char c, int *codage)
{
	*codage = *codage << 2;
	if (c == DIRECT_CHAR)
	{
		(*codage) += DIR_CODE;
		return (DIR_CODE);
	}
	else if (c == REG_CHAR)
	{
		(*codage) += REG_CODE;
		return (REG_CODE);
	}
	else
	{
		(*codage) += IND_CODE;
		return (IND_CODE);
	}
}

void		check_comm(t_val *assm, int i)
{
	if (assm->str[i + 1])
	{
		i = ft_skip_whitespaces(assm->str, i + 1);
		if ((assm->str[i] != COMMENT_CHAR) &&
			(assm->str[i] != ALT_COMMENT_CHAR))
			local_error(assm, "Syntax error after header command\n", i + 1);
	}
}

static void	free_label_struct(t_val *assm)
{
	t_replace	*mention;
	t_lbl		*label;

	while (assm->label)
	{
		free(assm->label->name);
		while (assm->label->mention)
		{
			mention = assm->label->mention;
			assm->label->mention = assm->label->mention->next;
			free(mention);
		}
		label = assm->label;
		assm->label = assm->label->next;
		free(label);
	}
}

void		free_asm(t_val *assm)
{
	if (assm)
	{
		if (assm->str)
			free(assm->str);
		if (assm->fd > 0)
			close(assm->fd);
		if (assm->r_str)
			free(assm->r_str);
		if (assm->file_name)
			free(assm->file_name);
		if (assm->data)
			free(assm->data);
		free_label_struct(assm);
		free(assm);
	}
}
