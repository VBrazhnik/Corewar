/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_placing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:03:22 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:03:23 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>
#include <unistd.h>

void	create_file(t_val *assm)
{
	assm->fd = open(assm->file_name, O_CREAT | O_TRUNC | O_WRONLY, 00644);
	if (assm->fd == -1)
		print_error(assm, "Can't create .cor file!\n");
	write(assm->fd, assm->data, assm->i);
	ft_printf("File %s created\n", assm->file_name);
	close(assm->fd);
}

void	place_size(t_val *assm)
{
	if (!(assm->r_str = ft_itoa(assm->i - NAME_COMM_LENGTH)))
		print_error(assm, "Malloc error (placing champion size)\n");
	assm->i = PROG_NAME_LENGTH + 8;
	place_num(assm, 0, 4);
	ft_strdel(&assm->r_str);
}

void	place_labels(t_val *assm)
{
	t_lbl		*label;
	t_replace	*mention;

	label = assm->label;
	while (label)
	{
		if (!label->initialized)
			print_error_label(assm, "A label is not defined\n",
					label->x, label->y);
		mention = label->mention;
		while (mention)
		{
			if (!(assm->r_str = ft_itoa(label->pos - mention->value)))
				print_error(assm, "Malloc error (placing labels)\n");
			assm->i = mention->idx;
			place_num(assm, 0, mention->size);
			ft_strdel(&assm->r_str);
			mention = mention->next;
		}
		label = label->next;
	}
}
