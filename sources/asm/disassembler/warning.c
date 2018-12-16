/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:18:51 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/15 12:23:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"
#include "ft_printf.h"

void	name_warning(size_t pos)
{
	int32_t	prefix;

	prefix = 4;
	ft_dprintf(2, "Name was completed with not null bytes — [%zu]\n",
																prefix + pos);
}

void	comment_warning(size_t pos)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4;
	ft_dprintf(2, "Comment was completed with not null bytes — [%zu]\n",
																prefix + pos);
}
