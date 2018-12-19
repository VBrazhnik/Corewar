/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:08:41 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 16:03:15 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_disasm.h"
#include "asm_error.h"
#include "ft_printf.h"
#include <fcntl.h>
#include <unistd.h>

void	disassemble(char *filename)
{
	int			fd;
	t_parser	*parser;

	if ((fd = open(filename, O_RDONLY)) == -1)
		terminate(ERR_OPEN_FILE);
	parser = init_bytecode_parser(fd);
	parse_bytecode(parser);
	validate_name(parser);
	validate_comment(parser);
	process_exec_code(parser);
	filename = replace_extension(filename, ".cor", ".s");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(ERR_CREATE_FILE);
	write_asm_file(fd, parser);
	ft_printf("Writing output program to %s\n", filename);
	ft_strdel(&filename);
	free_bytecode_parser(&parser);
}
