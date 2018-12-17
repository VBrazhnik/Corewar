/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:46:29 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 11:47:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"
#include "ft_printf.h"

void	op_code_error(t_parser *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Incorrect operator code at %u byte\n",
													prefix + parser->pos);
	exit(0);
}

void	arg_types_code_error(t_parser *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Incorrect code of arguments types at %u byte\n",
													prefix + parser->pos);
	exit(0);
}

void	length_error(t_parser *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "There is not enough bytes at %u byte\n",
														prefix + parser->pos);
	exit(0);
}

void	register_error(t_parser *parser)
{
	int32_t	prefix;

	prefix = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	ft_dprintf(2, "Incorrect register's id at %u byte\n",
														prefix + parser->pos);
	exit(0);
}
