/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:48:48 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/26 12:40:34 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vs.h"
#include "corewar_error.h"

t_vs	*init_vs(void)
{
	t_vs *vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		terminate(ERR_VS_INIT);
	return (vs);
}
