/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 15:22:11 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VS_H

# define VS_H

# include "libft.h"
# include <stdint.h>

typedef struct	s_vs
{
	size_t		speed;
	t_bool		sound;
}				t_vs;

/*
** Functions
*/

t_vs			*init_vs(void);

#endif
