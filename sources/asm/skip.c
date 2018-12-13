/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 06:34:57 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/12 00:05:14 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	skip_whitespaces(t_parser *parser, const char *line)
{
	while (is_whitespace(line[parser->column]))
		parser->column++;
}

void	skip_comment(t_parser *parser, const char *line)
{
	if (line[parser->column] == COMMENT_CHAR
		|| line[parser->column] == ALT_COMMENT_CHAR)
		while (!is_terminator(line[parser->column]))
			parser->column++;
}
