/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 07:34:23 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 04:19:23 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_error_msg.h"

t_bool	is_delimiter(int c)
{
	return (is_terminator(c)
			|| is_whitespace(c)
			|| c == DIRECT_CHAR
			|| c == SEPARATOR_CHAR
			|| c == '\"');
}

t_bool	is_register(const char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) >= 2 && ft_strlen(arg) <= 3 && arg[i] == REG_CHAR)
	{
		i++;
		while (ft_isdigit(arg[i]))
			i++;
		return (!arg[i]);
	}
	return (false);
}

char	*get_token_content(t_parser *parser, const char *line, unsigned start)
{
	char	*content;

	if (!(content = ft_strsub(line, start, parser->column - start)))
		terminate(ERR_STR_INIT);
	return (content);
}

void	update_parser_position(t_parser *parser, const char *line)
{
	parser->column++;
	while (line[parser->column] && line[parser->column] != '\"')
	{
		if (line[parser->column] == '\n')
		{
			parser->line++;
			parser->column = 0;
		}
		else
			parser->column++;
	}
	parser->column++;
}
