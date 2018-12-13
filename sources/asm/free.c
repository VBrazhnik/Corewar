/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 05:47:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 06:50:58 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_tokens(t_token **list)
{
	t_token	*current;
	t_token	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->content);
		free(delete);
	}
	*list = NULL;
}

void	free_mentions(t_mention **list)
{
	t_mention	*current;
	t_mention	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete);
	}
	*list = NULL;
}

void	free_labels(t_label **list)
{
	t_label	*current;
	t_label	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->name);
		free_mentions(&(delete->mentions));
		free(delete);
	}
	*list = NULL;
}

void	free_parser(t_parser **parser)
{
	free_tokens(&((*parser)->tokens));
	free((*parser)->name);
	free((*parser)->comment);
	free((*parser)->code);
	free_labels(&((*parser)->labels));
	free(*parser);
	*parser = NULL;
}
