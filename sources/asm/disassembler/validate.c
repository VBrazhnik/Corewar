/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:51:02 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 11:36:55 by vbrazhni         ###   ########.fr       */
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

void	validate_types_code(t_parser *parser,
							int8_t args_types_code,
							int args_num)
{
	int		arg_num;
	int8_t	type;

	arg_num = 4;
	while (arg_num > args_num)
	{
		type = (int8_t)((args_types_code >> (2 * (4 - arg_num))) & 0x3);
		if (type != 0)
		{
			types_code_warning((size_t)parser->pos);
			return ;
		}
		arg_num--;
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
