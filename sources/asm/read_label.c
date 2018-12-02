/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:02:55 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:02:57 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Checking label if it was mentioned from instructions
*/

int		mentioned_label(t_val *assm, int pos, int pc, int size)
{
	int		ret;
	t_lbl	*lbl;
	char	*name;
	int		i;

	i = pos;
	while (ft_strchr(LABEL_CHARS, assm->r_str[pos]))
		pos++;
	(pos <= i) ? local_error(assm, "No label name\n", assm->pos_x + 1) : 0;
	if (!assm->label)
	{
		create_label(assm, &assm->label, pc, size);
		return (pos);
	}
	if (!(name = ft_strsub(assm->r_str, 1, pos - 1)))
		print_error(assm, "Malloc error (creating label)\n");
	ret = 1;
	lbl = assm->label;
	while (lbl && (ret = ft_strcmp(lbl->name, name)) && lbl->next)
		lbl = lbl->next;
	free(name);
	(ret) ? create_label(assm, &lbl->next, pc, size) :
		upd_label(assm, &lbl, pc, size);
	return (pos);
}

/*
** Checking label if it was initialized
*/

int		init_label(t_val *assm, int i, int pc, int ret)
{
	t_lbl	*lbl;

	if (!(assm->r_str = ft_strsub(assm->str, i,
			ft_strchri(assm->str, LABEL_CHAR) - i)))
		print_error(assm, "Malloc error (creating label)\n");
	if ((ft_strchri(assm->str, LABEL_CHAR) - i) <= 0)
		local_error(assm, "Empty label\n", ft_strchri(assm->str, LABEL_CHAR)
		+ 1);
	if (!assm->label)
	{
		create_label(assm, &assm->label, pc, 0);
		return (ft_strchri(assm->str, LABEL_CHAR) + 1);
	}
	lbl = assm->label;
	while (lbl && (ret = ft_strcmp(lbl->name, assm->r_str)) && lbl->next)
		lbl = lbl->next;
	if (ret)
		create_label(assm, &lbl->next, pc, 0);
	else
	{
		upd_label(assm, &lbl, pc, 0);
		free(assm->r_str);
	}
	return (ft_strchri(assm->str, LABEL_CHAR) + 1);
}

/*
** Checking label
** pos == 1 - mentioning of the label from instruction
** pos == 0 - initialization of the label
** pc == 0 if initialization
** pc == assm->i - pos (pos is the size position in instruction)
** (used only when label is mentioned) size == position on the line + position
** on the instruction
*/

int		read_label(t_val *assm, int init, int pc, int size)
{
	int		i;

	if (!init)
	{
		i = ft_skip_whitespaces(assm->str, init);
		while (ft_strchr(LABEL_CHARS, assm->str[i]))
			i++;
		if (assm->str[i] != LABEL_CHAR)
			return (init);
		init = ft_skip_whitespaces(assm->str, init);
		i = init_label(assm, init, pc, 1);
		return (i);
	}
	i = mentioned_label(assm, init, pc, size);
	return (i);
}
