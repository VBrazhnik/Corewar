/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:47:24 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_disasm.h"
#include "asm_error.h"
#include <fcntl.h>
#include <unistd.h>

static int32_t	parse_int32(int fd)
{
	ssize_t	size;
	uint8_t	buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < 4)
		terminate(ERR_INVALID_FILE);
	return (bytecode_to_int32(buffer, 4));
}

static char		*parse_str(int fd, size_t len)
{
	ssize_t	size;
	char	*buffer;

	if (!(buffer = ft_strnew(len)))
		terminate(ERR_STR_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < (ssize_t)len)
		terminate(ERR_INVALID_FILE);
	return (buffer);
}

static uint8_t	*parse_code(int fd, size_t len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	if (!(buffer = ft_memalloc(len)))
		terminate(ERR_CODE_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		terminate(ERR_INVALID_FILE);
	return (buffer);
}

void			parse_bytecode(t_parser *parser)
{
	if (parse_int32(parser->fd) != COREWAR_EXEC_MAGIC)
		terminate(ERR_INVALID_MAGIC);
	parser->name = parse_str(parser->fd, PROG_NAME_LENGTH);
	if (parse_int32(parser->fd) != 0)
		terminate(ERR_NO_NULL);
	if ((parser->code_size = parse_int32(parser->fd)) < 0)
		terminate(ERR_INVALID_CODE_SIZE);
	parser->comment = parse_str(parser->fd, COMMENT_LENGTH);
	if (parse_int32(parser->fd) != 0)
		terminate(ERR_NO_NULL);
	parser->code = parse_code(parser->fd, (size_t)parser->code_size);
}
