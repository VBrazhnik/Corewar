/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:14 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:15 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ADD SUB
*/

void		args_reg_reg_reg(t_val *assm, int i)
{
	int tmp;

	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 3, i);
	tmp = i;
	i = reg_arg(assm, assm->r_str, 0, tmp);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	i = reg_arg(assm, assm->r_str, i, tmp + i);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	i = reg_arg(assm, assm->r_str, i, tmp + i);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + i + 1);
}

/*
** ADD
*/

void		check_add(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 4;
	i = ft_skip_whitespaces(assm->str, i);
	args_reg_reg_reg(assm, i);
	assm->data[assm->i++] = 84;
	i = get_arg(assm, 1, 1, 2);
	i = get_arg(assm, i + 1, 1, 3);
	get_arg(assm, i + 1, 1, 4);
}

/*
** SUB
*/

void		check_sub(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 5;
	i = ft_skip_whitespaces(assm->str, i);
	args_reg_reg_reg(assm, i);
	assm->data[assm->i++] = 84;
	i = 0;
	i = get_arg(assm, i + 1, 1, 2);
	i = get_arg(assm, i + 1, 1, 3);
	get_arg(assm, i + 1, 1, 4);
}
