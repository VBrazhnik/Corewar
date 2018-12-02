/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:00:17 by amedvedi          #+#    #+#             */
/*   Updated: 2018/11/01 14:00:18 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Check for instruction arguments
*/

int		skip_comma(t_val *assm, int i, char *error, int w)
{
	if (assm->r_str[i++] != SEPARATOR_CHAR)
		local_error(assm, error, w + i);
	i = ft_skip_whitespaces(assm->r_str, i);
	return (i);
}

int		reg_arg(t_val *assm, char *str, int i, int w)
{
	int		start;
	int		nbr;
	char	*tmp;

	if (str[i] != REG_CHAR)
		local_error(assm, "Bad parameter (not a register)\n", w + 1);
	i++;
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	if (!(tmp = ft_strsub(str, start, i - start)))
		print_error(assm, "Malloc error (checking register)\n");
	nbr = ft_atoi(tmp);
	free(tmp);
	if (nbr < 1 || nbr > REG_NUMBER)
		local_error(assm, "Bad reg number\n", w + 2);
	i = ft_skip_whitespaces(str, i);
	return (i);
}

int		dir_arg(t_val *assm, char *str, int i, int w)
{
	if (str[i] != DIRECT_CHAR)
		local_error(assm, "Bad parameter (not a direct)\n", w + i + 1);
	i++;
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
		if (i <= 2)
			local_error(assm, "Bad dir content\n", w + 1);
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(ft_isdigit(str[i])))
			local_error(assm, "Bad dir content\n", w + 1);
		while (ft_isdigit(str[i]))
			i++;
	}
	if (i <= 1)
		local_error(assm, "Bad dir content\n", w + 1);
	i = ft_skip_whitespaces(str, i);
	return (i);
}

int		ind_arg(t_val *assm, char *str, int i, int w)
{
	if (str[i] == DIRECT_CHAR || str[i] == REG_CHAR)
		print_error(assm, "Bad parameter (not an indirect)\n");
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, str[i]))
			i++;
		if (i <= 1)
			local_error(assm, "Bad ind content\n", w + 1);
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(ft_isdigit(str[i])))
			local_error(assm, "Bad ind content\n", w + 1);
		while (ft_isdigit(str[i]))
			i++;
	}
	i = ft_skip_whitespaces(str, i);
	return (i);
}

void	args_amount(t_val *assm, char *str, int nbr, int w)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] && str[i] != SEPARATOR_CHAR && !ft_iswhitespace(str[i]))
			i++;
		i = ft_skip_whitespaces(str, i);
		if (str[i] == SEPARATOR_CHAR)
			i = ft_skip_whitespaces(str, i + 1);
		nb++;
	}
	if (nb != nbr)
		local_error(assm, "Bad number of parameters\n", w + 1);
}
