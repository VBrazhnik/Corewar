/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:59:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/28 18:04:25 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error.h"
#include <fcntl.h>
#include <unistd.h>

static int32_t	bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

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

	if (!(buffer = malloc(len)))
		terminate(ERR_CODE_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERR_READ_FILE);
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		terminate(ERR_INVALID_FILE);
	return (buffer);
}

t_player		*parse_champion(char *filename, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);
	if ((fd = open(filename, O_RDONLY)) < 0)
		terminate(ERR_OPEN_FILE);
	if (parse_int32(fd) != COREWAR_EXEC_MAGIC)
		terminate(ERR_INVALID_MAGIC);
	player->name = parse_str(fd, PROG_NAME_LENGTH);
	if (parse_int32(fd) != 0)
		terminate(ERR_NO_NULL);
	if ((player->code_size = parse_int32(fd)) < 0 ||
		player->code_size > CHAMP_MAX_SIZE)
		terminate(ERR_INVALID_CODE_SIZE);
	player->comment = parse_str(fd, COMMENT_LENGTH);
	if (parse_int32(fd) != 0)
		terminate(ERR_NO_NULL);
	player->code = parse_code(fd, (size_t)player->code_size);
	return (player);
}
