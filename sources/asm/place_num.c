/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:03:03 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:03:05 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static intmax_t	check_num(char *num_str)
{
	int			i;
	intmax_t	nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_iswhitespace(num_str[i]))
		i++;
	if (num_str[i] == 43 || num_str[i] == 45)
	{
		if (num_str[i] == 45)
			sign = -1;
		i++;
	}
	while (ft_isdigit(num_str[i]))
	{
		nbr = nbr * 10 + (num_str[i++] - 48);
		if (nbr < 0)
		{
			return ((sign == 1) ? (9223372036854775807) : (0));
		}
	}
	i = sign * nbr;
	return (i);
}

static char		*nbr_to_str(t_val *assm, intmax_t nbr, int size)
{
	int		neg;
	char	*str;

	neg = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		print_error(assm, "Malloc error (converting number)\n");
	while (--size >= 0)
	{
		if (neg)
		{
			str[size] = (nbr % 256) - 1;
		}
		else
		{
			str[size] = (nbr % 256);
		}
		if (nbr < 0)
			neg = 1;
		nbr = nbr / 256;
	}
	return (str);
}

void			place_num(t_val *assm, int start, int size)
{
	intmax_t	nbr;
	char		*num_str;

	if (!(num_str = ft_strsub(assm->r_str, start,
			ft_strlen(assm->r_str) - start)))
		print_error(assm, "Malloc error (getting number)\n");
	nbr = check_num(num_str);
	free(num_str);
	num_str = nbr_to_str(assm, nbr, size);
	start = 0;
	while (size-- > 0)
		assm->data[assm->i++] = num_str[start++];
	free(num_str);
}
