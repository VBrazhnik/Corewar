/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:48:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 17:49:00 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(0);
}

int32_t	bytecode_to_int32(const uint8_t *bytecode, size_t size)
{
	int32_t	result;
	int		i;

	result = 0;
	i = 0;
	while (size)
	{
		result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	return (result);
}

t_bool	is_filename(const char *filename)
{
	if (filename && ft_strlen(filename) >= 4)
		return (!ft_strcmp((filename + ft_strlen(filename) - 4), ".cor"));
	else
		return (false);
}
