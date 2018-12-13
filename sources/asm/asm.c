/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:01:11 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 06:53:15 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "asm_error_msg.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void	process_asm(char *filename)
{
	int			fd;
	t_parser	*parser;
	t_token		*current;

	if ((fd = open(filename, O_RDONLY)) == -1)
		terminate(ERR_OPEN_CHAMPION);
	parser = init_parser(fd);
	parse_asm(parser);
	current = parser->tokens;
	process_info(parser, &current);
	process_code(parser, &current);
	replace_mentions(parser);
	filename = replace_extension(filename, ".s", ".cot");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		terminate(ERR_OPEN_CHAMPION);
	write_file(fd, parser);
	ft_printf("Writing output program to %s\n", filename);
	ft_strdel(&filename);
	free_parser(&parser);
}

int		main(int argc, char **argv)
{
	errno = 0;
	if (argc == 2 && is_filename(*(argv + 1), ".s"))
		process_asm(*(argv + 1));
	else
		print_help();
	return (0);
}
