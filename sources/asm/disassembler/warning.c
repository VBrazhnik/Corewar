/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:18:51 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 11:41:26 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"
#include "ft_printf.h"

void	name_warning(size_t pos)
{
	size_t prefix;

	prefix = 4;
	ft_dprintf(2, "Warning: Name was completed with not null bytes — [%zu]\n",
															prefix + pos + 1);
}

void	comment_warning(size_t pos)
{
	size_t prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_dprintf(2, "Warning: Comment was completed with not null bytes"\
												" — [%zu]\n", prefix + pos + 1);
}

void	types_code_warning(size_t pos)
{
	size_t prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Warning: Insignificant bits in code of arguments types are"\
									" not null — [%zu]\n", prefix + pos + 1);
}
