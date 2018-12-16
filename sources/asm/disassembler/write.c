/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:17:44 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 20:06:33 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

void	write_asm_file(int fd, t_parser *parser)
{
	t_statement	*current;
	unsigned	i;

	ft_dprintf(fd, ".name \"%s\"\n", parser->name);
	ft_dprintf(fd, ".comment \"%s\"\n\n", parser->comment);
	current = parser->statements;
	while (current)
	{
		ft_dprintf(fd, "%s", current->op->name);
		i = 0;
		while (i < current->op->args_num)
		{
			if (current->args_types[i] == T_DIR)
				ft_dprintf(fd, " %%%ld", (long)current->args[i]);
			else if (current->args_types[i] == T_IND)
				ft_dprintf(fd, " %ld", (long)current->args[i]);
			else if (current->args_types[i] == T_REG)
				ft_dprintf(fd, " r%ld", (long)current->args[i]);
			if (i < current->op->args_num - 1)
				ft_dprintf(fd, ",");
			i++;
		}
		ft_dprintf(fd, "\n");
		current = current->next;
	}
}
