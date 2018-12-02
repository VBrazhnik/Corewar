/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:16:02 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/01 15:16:03 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg_first_2(t_val *assm, int i, int codage, int i_pos)
{
	int ret;
	int pos;
	int size;

	pos = i + get_size(2, codage >> 6, 1);
	size = get_size(2, codage >> 6, 0);
	ret = get_arg(assm, pos, size, i_pos);
	return (ret);
}

int		get_arg_second_2(t_val *assm, int i, int codage, int i_pos)
{
	int ret;
	int pos;
	int size;

	pos = i + get_size(2, (codage >> 4) & 3, 1);
	size = get_size(2, (codage >> 4) & 3, 0);
	ret = get_arg(assm, pos, size, i_pos);
	return (ret);
}

int		get_arg_first_4(t_val *assm, int i, int codage, int i_pos)
{
	int ret;
	int pos;
	int size;

	pos = i + get_size(4, codage >> 6, 1);
	size = get_size(4, codage >> 6, 0);
	ret = get_arg(assm, pos, size, i_pos);
	return (ret);
}

int		get_arg_second_4(t_val *assm, int i, int codage, int i_pos)
{
	int ret;
	int pos;
	int size;

	pos = i + get_size(4, (codage >> 4) & 3, 1);
	size = get_size(4, (codage >> 4) & 3, 0);
	ret = get_arg(assm, pos, size, i_pos);
	return (ret);
}
