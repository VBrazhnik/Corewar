/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:10:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 16:05:05 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <errno.h>

int		main(int argc, char **argv)
{
	errno = 0;
	if (argc == 2 && is_filename(*(argv + 1), ".s"))
		assemble(*(argv + 1));
	else if (argc == 2 && is_filename(*(argv + 1), ".cor"))
		disassemble(*(argv + 1));
	else
		print_help();
	return (0);
}
