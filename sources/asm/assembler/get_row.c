/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 23:59:01 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/14 08:24:57 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_asm.h"
#include <unistd.h>

static int	divide_str(char **str, char **row)
{
	char	*new;
	char	*div;

	div = ft_strchrs(*str, '\n');
	div++;
	if (!(*row = ft_strsub(*str, 0, div - *str)))
		return (-1);
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int			get_row(const int fd, char **row)
{
	static char		*str = NULL;
	char			buff[BUFF_SIZE + 1];
	ssize_t			size;
	char			*tmp;

	if (fd < 0 || !row || read(fd, buff, 0) < 0)
		return (-1);
	while (!ft_strchrs(str, '\n'))
	{
		if (!(size = read(fd, buff, BUFF_SIZE)))
		{
			if (!(*row = str))
				return (0);
			str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
		if (!str)
			return (-1);
	}
	return (divide_str(&str, row));
}
