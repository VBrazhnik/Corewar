/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:56 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:58 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_all_arg(t_val *assm, int i, int pos, int *codage)
{
	int ret;

	if ((ret = get_type(assm->r_str[i], codage)) == 1)
		i = reg_arg(assm, assm->r_str, i, pos);
	else if (ret == 2)
		i = dir_arg(assm, assm->r_str, i, pos);
	else
		i = ind_arg(assm, assm->r_str, i, pos);
	return (i);
}

int		check_reg_dir(t_val *assm, int i, int pos, int *codage)
{
	int ret;

	if ((ret = get_type(assm->r_str[i], codage)) == 1)
		i = reg_arg(assm, assm->r_str, i, pos);
	else if (ret == 2)
		i = dir_arg(assm, assm->r_str, i, pos);
	else
		local_error(assm, "Bad argument\n", pos + 1);
	return (i);
}

int		check_dir_ind(t_val *assm, int i, int pos, int *codage)
{
	int ret;

	if ((ret = get_type(assm->r_str[i], codage)) == 2)
		i = dir_arg(assm, assm->r_str, i, pos);
	else if (ret == 3)
		i = ind_arg(assm, assm->r_str, i, pos);
	else
		local_error(assm, "Bad argument\n", pos + 1);
	return (i);
}
