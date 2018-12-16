/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:12:04 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/14 08:24:57 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_asm.h"

void	add_token(t_token **list, t_token *new)
{
	t_token	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			if (current->type == NEW_LINE && new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				current->next = new;
		}
		else
		{
			if (new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				*list = new;
		}
	}
}
