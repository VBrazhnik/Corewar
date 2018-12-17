/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:20:35 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 15:21:48 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_asm.h"
#include "ft_printf.h"

void	name_error(void)
{
	ft_dprintf(2, "Champion name too long (Max length %u)\n", PROG_NAME_LENGTH);
	exit(1);
}

void	comment_error(void)
{
	ft_dprintf(2, "Champion comment too long (Max length %u)\n",
																COMMENT_LENGTH);
	exit(1);
}
