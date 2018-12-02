/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:00:36 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:00:37 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Getting arguments from instruction.
** Gets the information from argument, saves it and skips to next argument.
** i - position at the line
** size - Label size of the operation.
** octet - concerns labels, position to write to the value of the label
*/

int			get_arg(t_val *assm, int i, int size, int pos)
{
	char	*tmp;
	int		y;

	if (assm->r_str[i] == LABEL_CHAR)
	{
		tmp = assm->r_str;
		if (!(assm->r_str = ft_strsub(assm->r_str, i,
			ft_strlen(assm->r_str) - i)))
			print_error(assm, "Malloc error (getting label)\n");
		free(tmp);
		read_label(assm, 1, (assm->i - pos), size);
		y = -1;
		while (++y < size)
			assm->data[assm->i++] = 0;
		i = 0;
	}
	else
		place_num(assm, i, size);
	while (assm->r_str[i] && !ft_iswhitespace(assm->r_str[i]) &&
		(assm->r_str[i] != SEPARATOR_CHAR))
		i++;
	while (assm->r_str[i] && (ft_iswhitespace(assm->r_str[i]) ||
		assm->r_str[i] == SEPARATOR_CHAR))
		i++;
	return (i);
}
