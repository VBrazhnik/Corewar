/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:42:16 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:07:36 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

static void	free_statements(t_statement **list)
{
	t_statement	*current;
	t_statement	*delete;

	current = *list;
	while (current)
	{
		delete = current;
		current = current->next;
		ft_memdel((void **)&delete);
	}
	*list = NULL;
}

void		free_bytecode_parser(t_parser **parser)
{
	ft_strdel(&((*parser)->name));
	ft_strdel(&((*parser)->comment));
	ft_memdel((void **)&((*parser)->code));
	free_statements(&((*parser)->statements));
	ft_memdel((void **)parser);
}
