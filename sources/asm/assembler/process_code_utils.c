/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_code_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 03:47:54 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"

void			update_code_buff(t_parser *parser)
{
	parser->code_size += CHAMP_MAX_SIZE;
	if (!(parser->code = (char *)realloc(parser->code,
				((size_t)parser->code_size + MAX_STATEMENT_SIZE))))
		terminate(ERR_STR_INIT);
}

t_op			*get_op(char *name)
{
	unsigned	i;

	i = 0;
	while (i < (sizeof(g_op) / sizeof(t_op)))
	{
		if (!ft_strcmp(g_op[i].name, name))
			return (&g_op[i]);
		i++;
	}
	return (NULL);
}

static uint8_t	get_arg_code(int8_t type)
{
	if (type == T_DIR)
		return (DIR_CODE);
	else if (type == T_REG)
		return (REG_CODE);
	else
		return (IND_CODE);
}

void			update_types_code(int8_t *types_code, int8_t type, int arg_num)
{
	(*types_code) |= (get_arg_code(type) << 2 * (4 - arg_num - 1));
}
