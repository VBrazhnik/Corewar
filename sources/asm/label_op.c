/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:02:55 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:02:57 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Updating the existing label if the initialization was done or another
** another mention in instructions
*/

void	upd_label(t_val *assm, t_lbl **tmp, int pc, int size)
{
	t_replace	*tmp_old;
	t_replace	*tmp_new;

	if (size == 0 && !(*tmp)->initialized)
	{
		(*tmp)->initialized = 1;
		(*tmp)->pos = assm->i - NAME_COMM_LENGTH;
	}
	else if (size != 0)
	{
		tmp_old = (*tmp)->mention;
		if (!(tmp_new = (t_replace*)malloc(sizeof(t_replace) * 1)))
			print_error(assm, "Malloc error (creating index structure)\n");
		if (!(*tmp)->mention)
			(*tmp)->mention = tmp_new;
		else
			while (tmp_old->next)
				tmp_old = tmp_old->next;
		if ((*tmp)->mention != tmp_new)
			tmp_old->next = tmp_new;
		tmp_new->idx = assm->i;
		tmp_new->size = size;
		tmp_new->value = pc - NAME_COMM_LENGTH;
		tmp_new->next = NULL;
	}
}

/*
** Creating label if either it was initialized or mentioned in instruction
*/

void	create_label_unconf(t_val *assm, t_lbl **tmp, int pc, int size)
{
	int i;

	(*tmp)->initialized = 0;
	i = 1;
	while (ft_strchr(LABEL_CHARS, assm->r_str[i]))
		i++;
	if (!((*tmp)->name = ft_strsub(assm->r_str, 1, i - 1)))
		print_error(assm, "Malloc error (creating label)\n");
	(*tmp)->pos = 0;
	if (!((*tmp)->mention = (t_replace*)malloc(sizeof(t_replace) * 1)))
		print_error(assm, "Malloc error (creating label structure)\n");
	(*tmp)->x = assm->pos_x + 1;
	(*tmp)->y = assm->pos_y;
	(*tmp)->mention->idx = assm->i;
	(*tmp)->mention->size = size;
	(*tmp)->mention->value = pc - NAME_COMM_LENGTH;
	(*tmp)->mention->next = NULL;
}

void	create_label(t_val *assm, t_lbl **tmp, int pc, int size)
{
	if (!(*tmp = (t_lbl*)malloc(sizeof(t_lbl) * 1)))
		print_error(assm, "Malloc error (creating label structure)\n");
	(*tmp)->next = NULL;
	if (size == 0)
	{
		(*tmp)->initialized = 1;
		(*tmp)->name = assm->r_str;
		(*tmp)->pos = assm->i - NAME_COMM_LENGTH;
		(*tmp)->mention = NULL;
	}
	else
		create_label_unconf(assm, tmp, pc, size);
}
