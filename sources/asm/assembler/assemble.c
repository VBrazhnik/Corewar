/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:09:25 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 16:03:15 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_asm.h"
#include "asm_error.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

void	assemble(char *filename)
{
	int			fd;
	t_parser	*parser;
	t_token		*current;

	if ((fd = open(filename, O_RDONLY)) == -1)
		terminate(ERR_OPEN_FILE);
	parser = init_asm_parser(fd);
	parse_asm(parser);
	current = parser->tokens;
	process_info(parser, &current);
	process_asm_code(parser, &current);
	replace_mentions(parser);
	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(ERR_CREATE_FILE);
	write_bytecode_file(fd, parser);
	ft_printf("Writing output program to %s\n", filename);
	ft_strdel(&filename);
	free_asm_parser(&parser);
}
