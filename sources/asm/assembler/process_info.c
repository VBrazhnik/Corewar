/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:00:20 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"

static void	process_name(t_parser *parser, t_token **current)
{
	if ((*current)->type == STRING)
	{
		if (!(parser->name = ft_strsub((*current)->content,
					1, ft_strlen((*current)->content) - 2)))
			terminate(ERR_STR_INIT);
		if (ft_strlen(parser->name) > PROG_NAME_LENGTH)
			name_error();
		(*current) = (*current)->next;
	}
	else
		token_error(*current);
}

static void	process_comment(t_parser *parser, t_token **current)
{
	if ((*current)->type == STRING)
	{
		if (!(parser->comment = ft_strsub((*current)->content,
					1, ft_strlen((*current)->content) - 2)))
			terminate(ERR_STR_INIT);
		if (ft_strlen(parser->comment) > COMMENT_LENGTH)
			comment_error();
		(*current) = (*current)->next;
	}
	else
		token_error(*current);
}

void		process_info(t_parser *parser, t_token **current)
{
	while (!parser->name || !parser->comment)
	{
		if ((*current)->type == COMMAND
			&& !parser->name
			&& !ft_strcmp((*current)->content, NAME_CMD_STRING))
		{
			(*current) = (*current)->next;
			process_name(parser, current);
			if ((*current)->type != NEW_LINE)
				token_error(*current);
		}
		else if ((*current)->type == COMMAND
			&& !parser->comment
			&& !ft_strcmp((*current)->content, COMMENT_CMD_STRING))
		{
			(*current) = (*current)->next;
			process_comment(parser, current);
			if ((*current)->type != NEW_LINE)
				token_error(*current);
		}
		else
			token_error(*current);
		(*current) = (*current)->next;
	}
}
