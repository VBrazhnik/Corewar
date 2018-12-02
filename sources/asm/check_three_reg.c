/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_three_reg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:02 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:03 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** AND OR XOR
*/

void		args_three_three_reg(t_val *assm, int i, int *codage)
{
	int		tmp;

	if (!(assm->r_str = ft_strsub(assm->str, i, ft_strlen(assm->str) - i)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 3, i);
	tmp = i;
	i = 0;
	i = check_all_arg(assm, i, tmp, codage);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	i = check_all_arg(assm, i, tmp + i, codage);
	i = skip_comma(assm, i, "Bad argument (separator)\n", tmp);
	get_type(assm->r_str[i], codage);
	i = reg_arg(assm, assm->r_str, i, tmp + i);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", tmp + i + 1);
	(*codage) = (*codage) << 2;
}

/*
** AND
*/

void		check_and(t_val *assm, int i)
{
	int		codage;
	int		i_pos;
	int		tmp;

	codage = 0;
	i_pos = 2;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 6;
	i = ft_skip_whitespaces(assm->str, i);
	args_three_three_reg(assm, i, &codage);
	assm->data[assm->i++] = codage;
	tmp = i;
	assm->pos_x = i;
	i = 0;
	i = get_arg_first_4(assm, i, codage, i_pos);
	i_pos += get_size(4, codage >> 6, 0);
	assm->pos_x = i + tmp + 1;
	i = get_arg_second_4(assm, i, codage, i_pos);
	i_pos += get_size(4, (codage >> 4) & 3, 0);
	get_arg(assm, i + 1, 1, i_pos);
}

/*
** OR
*/

void		check_or(t_val *assm, int i)
{
	int		codage;
	int		i_pos;
	int		tmp;

	codage = 0;
	i_pos = 2;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 7;
	i = ft_skip_whitespaces(assm->str, i);
	args_three_three_reg(assm, i, &codage);
	assm->data[assm->i++] = codage;
	tmp = i;
	assm->pos_x = i;
	i = 0;
	i = get_arg_first_4(assm, i, codage, i_pos);
	i_pos += get_size(4, codage >> 6, 0);
	assm->pos_x = i + tmp + 1;
	i = get_arg_second_4(assm, i, codage, i_pos);
	i_pos += get_size(4, (codage >> 4) & 3, 0);
	get_arg(assm, i + 1, 1, i_pos);
}

/*
** XOR
*/

void		check_xor(t_val *assm, int i)
{
	int		codage;
	int		i_pos;
	int		tmp;

	codage = 0;
	i_pos = 2;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 8;
	i = ft_skip_whitespaces(assm->str, i);
	args_three_three_reg(assm, i, &codage);
	assm->data[assm->i++] = codage;
	tmp = i;
	assm->pos_x = i;
	i = 0;
	i = get_arg_first_4(assm, i, codage, i_pos);
	i_pos += get_size(4, codage >> 6, 0);
	assm->pos_x = i + tmp + 1;
	i = get_arg_second_4(assm, i, codage, i_pos);
	i_pos += get_size(4, (codage >> 4) & 3, 0);
	get_arg(assm, i + 1, 1, i_pos);
}
