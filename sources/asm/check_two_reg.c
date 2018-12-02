/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two_reg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:15:49 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:15:50 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** LD LLD
*/

void		args_two_reg(t_val *assm, int i, int *codage)
{
	int		tmp;

	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 2, i);
	tmp = i;
	i = 0;
	i = check_dir_ind(assm, i, tmp, codage);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	get_type(assm->r_str[i], codage);
	i = reg_arg(assm, assm->r_str, i, tmp + i);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + 1 + i);
	(*codage) = (*codage) << 4;
}

/*
** LD
*/

void		check_ld(t_val *assm, int i)
{
	int		codage;
	int		i_pos;

	i_pos = 2;
	codage = 0;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 2;
	i = ft_skip_whitespaces(assm->str, i);
	args_two_reg(assm, i, &codage);
	assm->data[assm->i++] = codage;
	assm->pos_x = i;
	i = 0;
	i = get_arg_first_4(assm, i, codage, i_pos);
	i_pos += get_size(4, codage >> 6, 0);
	get_arg(assm, i + 1, 1, i_pos);
}

/*
** LLD
*/

void		check_lld(t_val *assm, int i)
{
	int		codage;
	int		i_pos;

	i_pos = 2;
	codage = 0;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 13;
	i = ft_skip_whitespaces(assm->str, i);
	args_two_reg(assm, i, &codage);
	assm->data[assm->i++] = codage;
	assm->pos_x = i;
	i = 0;
	i = get_arg_first_4(assm, i, codage, i_pos);
	i_pos += get_size(4, codage >> 6, 0);
	get_arg(assm, i + 1, 1, i_pos);
}
