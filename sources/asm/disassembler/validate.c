/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:51:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 15:53:27 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_disasm.h"

void	validate_name(t_parser *parser)
{
	size_t i;

	i = ft_strlen(parser->name);
	while (i < PROG_NAME_LENGTH)
	{
		if (parser->name[i])
		{
			name_warning(i);
			return ;
		}
		i++;
	}
}

void	validate_comment(t_parser *parser)
{
	size_t i;

	i = ft_strlen(parser->comment);
	while (i < COMMENT_LENGTH)
	{
		if (parser->comment[i])
		{
			comment_warning(i);
			return ;
		}
		i++;
	}
}

t_bool	is_arg_types_valid(t_statement *statement)
{
	int32_t i;

	i = 0;
	while (i < statement->op->args_num)
	{
		if (!(statement->args_types[i] & statement->op->args_types[i]))
			return (false);
		i++;
	}
	return (true);
}
