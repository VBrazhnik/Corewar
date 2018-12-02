/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:56 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:58 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** STI
*/

void		args_sti(t_val *assm, int p, int *codage)
{
	int		i;

	i = 0;
	if (!(assm->r_str = ft_strsub(assm->str, p, ft_strlen(assm->str) - p)))
		print_error(assm, "Malloc error (counting args)\n");
	args_amount(assm, assm->r_str, 3, p);
	get_type(assm->r_str[i], codage);
	i = reg_arg(assm, assm->r_str, i, p);
	i = skip_comma(assm, i, "Bad argument (separator)\n", p);
	i = check_all_arg(assm, i, p + i, codage);
	i = skip_comma(assm, i, "Bad argument (separator)\n", p);
	i = check_reg_dir(assm, i, p + i, codage);
	if (assm->r_str[i])
		local_error(assm, "Bad character after arguments\n", p + i + 1);
	(*codage) = (*codage) << 2;
}

/*
** adding 11 as a 0xB - sti hexa
** codage - codage of the arguments
** 2 arg: i + get_size(2, codage >> 6, 1) - as a position to start reading
** 3 arg: get_size(2, codage >> 6, 0) - to have the size of an argument
** 4 arg: i_pos - concerns labels, position on the instruction to
** correctly write to the label value
*/

void		check_sti(t_val *assm, int i)
{
	int		codage;
	int		i_pos;
	int		tmp;

	codage = 0;
	i_pos = 2;
	ft_strdel(&assm->r_str);
	assm->data[assm->i++] = 11;
	i = ft_skip_whitespaces(assm->str, i);
	args_sti(assm, i, &codage);
	assm->data[assm->i++] = codage;
	tmp = i;
	i = 0;
	i = get_arg(assm, i + 1, 1, 2);
	i_pos += 1;
	assm->pos_x = i + tmp;
	tmp += i;
	i = get_arg(assm, i + get_size(2, (codage >> 4) & 3, 1), get_size(2,
			(codage >> 4) & 3, 0), 3);
	i_pos += get_size(2, (codage >> 4) & 3, 0);
	assm->pos_x = i + tmp + 1;
	get_arg(assm, i + get_size(2, (codage >> 2) & 3, 1), get_size(2,
			(codage >> 2) & 3, 0), i_pos);
}
