/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 05:47:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:43:19 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_asm.h"

static void	free_tokens(t_token **list)
{
	t_token	*current;
	t_token	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_strdel(&(delete->content));
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

static void	free_mentions(t_mention **list)
{
	t_mention	*current;
	t_mention	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

static void	free_labels(t_label **list)
{
	t_label	*current;
	t_label	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_strdel(&(delete->name));
		free_mentions(&(delete->mentions));
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		free_asm_parser(t_parser **parser)
{
	free_tokens(&((*parser)->tokens));
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_strdel(&((*parser)->code));
	free_labels(&((*parser)->labels));
	ft_memdel((void **)parser);
}
