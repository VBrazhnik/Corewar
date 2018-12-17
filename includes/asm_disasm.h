/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_disasm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:36:23 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/17 11:19:40 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DISASM_H

# define ASM_DISASM_H

# include "libft.h"
# include "op.h"
# include "asm_op.h"

# define INDEX(X) ((X) - 1)

typedef struct			s_statement
{
	t_op				*op;
	uint8_t				args_types[3];
	int32_t				args[3];
	struct s_statement	*next;
}						t_statement;

/*
** Parser
*/

typedef struct			s_parser
{
	int					fd;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
	int32_t				pos;
	t_statement			*statements;
}						t_parser;

/*
** Functions
*/

/*
** Init
*/

t_parser				*init_bytecode_parser(int fd);

t_statement				*init_statement();

/*
** Parse
*/

void					parse_bytecode(t_parser *parser);

/*
** Validate
*/

void					validate_name(t_parser *parser);

void					validate_comment(t_parser *parser);

void					validate_types_code(t_parser *parser,
											int8_t args_types_code,
											int args_num);

t_bool					is_arg_types_valid(t_statement *statement);

/*
** Warning
*/

void					name_warning(size_t pos);

void					comment_warning(size_t pos);

void					types_code_warning(size_t pos);

/*
** Process
*/

void					process_exec_code(t_parser *parser);

void					process_arg_types(t_parser *parser,
										t_statement *statement);

/*
** Statement
*/

void					add_statement(t_statement **list, t_statement *new);

/*
** Write
*/

void					write_asm_file(int fd, t_parser *parser);

/*
** Free
*/

void					free_bytecode_parser(t_parser **parser);

/*
** Error
*/

void					op_code_error(t_parser *parser);

void					arg_types_code_error(t_parser *parser);

void					length_error(t_parser *parser);

void					register_error(t_parser *parser);

/*
** Utils
*/

int32_t					bytecode_to_int32(const uint8_t *bytecode, size_t size);

#endif
