/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:08:40 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/14 11:06:44 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_asm.h"
#include "ft_printf.h"

void	print_help(void)
{
	ft_printf("Usage: ./asm (champion.s|champion.cor)\n");
	ft_printf("    champion.s   — from assemble to bytecode\n");
	ft_printf("    champion.cor — from bytecode to assemble\n");
}
