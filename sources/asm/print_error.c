/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:03:29 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:03:30 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_error_label(t_val *assm, char *msg, int x, int y)
{
	ft_printf("line : %d, col : %d Error: ", y, x);
	free_asm(assm);
	ft_printf("%s", msg);
	system("Leaks ASM");
	exit(EXIT_FAILURE);
}

void		local_error(t_val *assm, char *msg, int what)
{
	ft_printf("line : %d, col : %d Error: ", assm->pos_y, what);
	free_asm(assm);
	ft_printf("%s", msg);
	system("Leaks ASM");
	exit(EXIT_FAILURE);
}

void		print_error(t_val *assm, char *msg)
{
	free_asm(assm);
	ft_printf("%s", msg);
	system("Leaks ASM");
	exit(EXIT_FAILURE);
}
