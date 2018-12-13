/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:08:40 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 04:49:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"

void	print_help(void)
{
	ft_printf("Usage: ./asm (champion.s|champion.cor)\n");
	ft_printf("\t* champion.s   — from assembler to bytecode\n");
	ft_printf("\t* champion.cor — from bytecode to assembler\n");
}
