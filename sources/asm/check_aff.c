/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:17:04 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:17:06 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** AFF
*/

void	args_aff(t_val *assm, int i)
{
	int tmp;

	tmp = i;
	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 1, i);
	i = reg_arg(assm, assm->r_str, 0, tmp);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + 1);
}

void	check_aff(t_val *assm, int i)
{
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 16;
	i = ft_skip_whitespaces(assm->str, i);
	args_aff(assm, i);
	assm->data[assm->i++] = 0x40;
	get_arg(assm, 1, 1, 2);
}
