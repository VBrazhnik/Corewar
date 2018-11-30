/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:59:53 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 15:59:54 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_error_msg.h"
#include <fcntl.h>
#include <unistd.h>

static int32_t	parse_int32(int fd)
{
	ssize_t		size;
	uint8_t		buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1)
		terminate(ERR_READ_CHAMPION);
	if (size < 4)
		terminate(ERR_INVALID_CHAMPION);
	return (bytecode_to_int32_ptr(buffer, 4));
}

static char		*parse_str(int fd, size_t len)
{
	ssize_t		size;
	char		*buffer;

	if (!(buffer = ft_strnew(len)))
		terminate(ERR_STR_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERR_READ_CHAMPION);
	if (size < (ssize_t)len)
		terminate(ERR_INVALID_CHAMPION);
	return (buffer);
}

static uint8_t	*parse_code(int fd, size_t len)
{
	ssize_t		size;
	uint8_t		*buffer;

	if (!(buffer = malloc(len)))
		terminate(ERR_CODE_INIT);
	size = read(fd, buffer, len);
	if (size == -1)
		terminate(ERR_READ_CHAMPION);
	if (size < (ssize_t)len || read(fd, buffer, 0) != 0)
		terminate(ERR_INVALID_CHAMPION);
	return (buffer);
}

t_player		*parse_champion(char *filename, int id)
{
	t_player	*player;
	int			fd;

	player = init_player(id);
	if ((fd = open(filename, O_RDONLY)) < 0)
		terminate(ERR_OPEN_CHAMPION);
	if (parse_int32(fd) != COREWAR_EXEC_MAGIC)
		terminate(ERR_INVALID_MAGIC);
	player->name = parse_str(fd, PROG_NAME_LENGTH);
	if (parse_int32(fd) != 0)
		terminate(ERR_NO_NULL);
	if ((player->code_size = parse_int32(fd)) <= 0 ||
		player->code_size > CHAMP_MAX_SIZE)
		terminate(ERR_INVALID_CODE_SIZE);
	player->comment = parse_str(fd, COMMENT_LENGTH);
	if (parse_int32(fd) != 0)
		terminate(ERR_NO_NULL);
	player->code = parse_code(fd, (size_t)player->code_size);
	return (player);
}
