/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/29 02:11:13 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmpi(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i])
		return (i);
	return (-1);
}
