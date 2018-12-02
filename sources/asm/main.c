/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:03:12 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:03:14 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>
#include <unistd.h>

void	asm_file(t_val *assm, char *filename)
{
	if (!(assm->r_str = ft_strsub(filename, ft_strlen(filename) - 2, 2)))
		print_error(assm, "Malloc error (file extension)\n");
	if (ft_strcmp(assm->r_str, ".s"))
		print_error(assm, "Bad extension\n");
	ft_strdel(&assm->r_str);
	if ((assm->fd = open(filename, O_RDONLY)) == -1)
		print_error(assm, "Error when opening file\n");
	if (!(assm->r_str = ft_strndup(filename, ft_strlen(filename) - 2)))
		print_error(assm, "Malloc error when creating .cor\n");
	if (!(assm->file_name = ft_strjoin(assm->r_str, ".cor")))
		print_error(assm, "Malloc error when creating .cor\n");
	ft_strdel(&assm->r_str);
}

void	main_asm(t_val *assm, char **argv, int i)
{
	if (!(assm = (t_val*)malloc(sizeof(t_val) * 1)))
		print_error(assm, "Malloc error (asm struct)\n");
	assm->i = 4;
	assm->fd = 0;
	assm->pos_y = 0;
	assm->pos_x = 0;
	assm->str = NULL;
	assm->r_str = NULL;
	assm->file_name = NULL;
	assm->data = NULL;
	assm->label = NULL;
	asm_file(assm, argv[i]);
	read_bot_name_comm(assm, 0, 1);
	read_bot_op(assm);
	close(assm->fd);
	create_file(assm);
	free_asm(assm);
}

int		main(int argc, char **argv)
{
	t_val	*assm;
	int		i;

	i = 1;
	while (argc >= 2 && i < argc)
	{
		assm = NULL;
		main_asm(assm, argv, i);
		i++;
	}
	if (argc < 2)
		ft_printf("\nUsage : ./asm example.s (or multiple files)\n");
	system("Leaks ASM");
	return (0);
}
