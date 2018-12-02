/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:15:38 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:15:40 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** LIVE ZJMP FORK LFORK
*/

void		args_dir(t_val *assm, int i)
{
	int tmp;

	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 1, i);
	tmp = i;
	i = dir_arg(assm, assm->r_str, 0, i);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + i + 1);
}

/*
** LIVE
*/

void		check_live(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 1;
	i = ft_skip_whitespaces(assm->str, i);
	args_dir(assm, i);
	assm->pos_x = i;
	get_arg(assm, 1, 4, 1);
}

/*
** ZJMP
*/

void		check_zjmp(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 9;
	i = ft_skip_whitespaces(assm->str, i);
	args_dir(assm, i);
	assm->pos_x = i;
	get_arg(assm, 1, 2, 1);
}

/*
** FORK
*/

void		check_fork(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 12;
	i = ft_skip_whitespaces(assm->str, i);
	args_dir(assm, i);
	assm->pos_x = i;
	get_arg(assm, 1, 2, 1);
}

/*
** LFORK
*/

void		check_lfork(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 15;
	i = ft_skip_whitespaces(assm->str, i);
	assm->pos_x = i;
	args_dir(assm, i);
	get_arg(assm, 1, 2, 1);
}
