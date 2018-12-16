/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:37:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"
#include <fcntl.h>
#include <unistd.h>

void		write_bytecode_file(int fd, t_parser *parser)
{
	int32_t	len;
	int32_t	pos;
	char	*bytecode;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + parser->pos;
	if (!(bytecode = ft_strnew((size_t)len)))
		terminate(ERR_STR_INIT);
	int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->name, ft_strlen(parser->name));
	pos += PROG_NAME_LENGTH;
	pos += 4;
	int32_to_bytecode(bytecode, pos, parser->pos, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->comment, ft_strlen(parser->comment));
	pos += COMMENT_LENGTH;
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->code, (size_t)parser->pos);
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}
