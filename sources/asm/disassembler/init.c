/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:38:52 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 19:47:53 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_disasm.h"
#include "asm_error.h"

t_parser	*init_bytecode_parser(int fd)
{
	t_parser *parser;

	if (!(parser = (t_parser *)ft_memalloc(sizeof(t_parser))))
		terminate(ERR_PARSER_INIT);
	parser->fd = fd;
	parser->name = NULL;
	parser->comment = NULL;
	parser->code_size = 0;
	parser->code = NULL;
	parser->pos = 0;
	parser->statements = NULL;
	return (parser);
}

t_statement	*init_statement(void)
{
	t_statement *statement;

	if (!(statement = (t_statement *)ft_memalloc(sizeof(t_statement))))
		terminate(ERR_STATEMENT_INIT);
	statement->op = NULL;
	statement->next = NULL;
	return (statement);
}
