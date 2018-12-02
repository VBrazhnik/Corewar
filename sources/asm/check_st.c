/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:48 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:50 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ST
*/

void		args_st(t_val *assm, int i, int *codage)
{
	int		ret;
	int		tmp;

	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 2, i);
	tmp = i;
	i = 0;
	get_type(assm->r_str[i], codage);
	i = reg_arg(assm, assm->r_str, i, tmp);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	if ((ret = get_type(assm->r_str[i], codage)) == 1)
		i = reg_arg(assm, assm->r_str, i, tmp + i);
	else if (ret == 3)
		i = ind_arg(assm, assm->r_str, i, tmp + i);
	else
		local_error(assm, "Bad argument\n", tmp + i + 1);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + i + 1);
	(*codage) = (*codage) << 4;
}

void		check_st(t_val *assm, int i)
{
	int		codage;
	int		tmp;

	codage = 0;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 3;
	i = ft_skip_whitespaces(assm->str, i);
	args_st(assm, i, &codage);
	assm->data[assm->i++] = codage;
	tmp = i;
	i = 0;
	i = get_arg(assm, i + 1, 1, 2);
	assm->pos_x = tmp + i;
	get_arg(assm, i + get_size(4, (codage >> 4) & 3, 1), get_size(4,
			(codage >> 4) & 3, 0), 3);
}
