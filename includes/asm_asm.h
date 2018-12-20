/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_asm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:35:04 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/19 15:56:57 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ASM_H

# define ASM_ASM_H

# include "libft.h"
# include "op.h"
# include "asm_op.h"

# define BUFF_SIZE 2048

# define MAX_STATEMENT_SIZE 14

# define REG_CHAR 'r'

# define COMMAND_CHAR '.'

/*
** Token Type
*/

typedef enum
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}	t_type;

static char				*g_type[] = {
	"COMMAND",
	"STRING",
	"LABEL",
	"OPERATOR",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"NEW_LINE",
	"END"
};

/*
** Token
*/

/*
** content — content of token
** type    — type of token
** row     — row, where token is placed
** column  — column, where token is placed
** next    — pointer to the next token
*/

typedef struct			s_token
{
	char				*content;
	t_type				type;
	unsigned			row;
	unsigned			column;
	struct s_token		*next;
}						t_token;

/*
** Mention
*/

/*
** row    — row, where mention was found in assemble-file
** column — column, where mention was found in assemble-file
** pos    — number of byte where mention is placed
** op_pos — number of byte where operator code is placed
** size   — number of bytes which store a value of mention at pos
** next   — pointer to the next mention
*/

typedef struct			s_mention
{
	unsigned			row;
	unsigned			column;
	int32_t				pos;
	int32_t				op_pos;
	size_t				size;
	struct s_mention	*next;
}						t_mention;

/*
** Label
*/

/*
** name     — name of label
** op_pos   — number of byte, at which label points
** mentions — list of mentions
** next     — pointer to the next label
*/

typedef struct			s_label
{
	char				*name;
	int32_t				op_pos;
	t_mention			*mentions;
	struct s_label		*next;
}						t_label;

/*
** Assembler's Parser
*/

/*
** fd        — file descriptor of assemble-file
** row       — row of assemble-file, which parser processes now
** column    — column of assemble-file, which parser processes now
** tokens    — list of tokens
** pos       — number of byte, at which parser writes now
** op_pos    — number of byte, at which op_code of current statement is placed
** name      — name of champion
** comment   — comment of champion
** code      — executable code of champion
** code_size — size of champion's executable code
** labels    — list of labels
*/

typedef struct			s_parser
{
	int					fd;
	unsigned			row;
	unsigned			column;
	t_token				*tokens;
	int32_t				pos;
	int32_t				op_pos;
	char				*name;
	char				*comment;
	char				*code;
	int32_t				code_size;
	t_label				*labels;
}						t_parser;

/*
** Functions
*/

/*
** Init
*/

t_parser				*init_asm_parser(int fd);

t_token					*init_token(t_parser *parser, t_type type);

t_label					*init_label(char *name, int op_pos);

t_mention				*init_mention(t_parser *parser,
										t_token *token,
										size_t size);

/*
** Parse
*/

int						get_row(int fd, char **row);

void					parse_asm(t_parser *parser);

/*
** Parse Utils
*/

int						is_whitespace(int c);

t_bool					is_delimiter(int c);

t_bool					is_register(const char *arg);

char					*get_token_content(t_parser *parser,
											const char *row,
											unsigned start);

char					*join_str(char **str1, char **str2);

void					update_parser_position(t_parser *parser,
											const char *row);

void					update_row(char **row, char *ptr);

/*
** Skip
*/

void					skip_whitespaces(t_parser *parser, const char *row);

void					skip_comment(t_parser *parser, const char *row);

/*
** Token
*/

void					add_token(t_token **list, t_token *new);

/*
** Label
*/

void					add_label(t_label **list, t_label *new);

void					add_mention(t_mention **list, t_mention *new);

t_label					*find_label(t_label *list, char *name);

void					replace_mentions(t_parser *file);

/*
** Process
*/

void					process_info(t_parser *parser, t_token **current);

void					process_asm_code(t_parser *parser, t_token **current);

int8_t					process_arg(t_parser *parser,
									t_token **current,
									t_op *op,
									int arg_num);

/*
** Process Utils
*/

void					update_code_buff(t_parser *parser);

t_op					*get_op(char *name);

void					update_types_code(int8_t *types_code,
										int8_t type,
										int arg_num);

/*
** Write
*/

void					write_bytecode_file(int fd, t_parser *parser);

/*
** Free
*/

void					free_asm_parser(t_parser **parser);

/*
** Error
*/

void					lexical_error(t_parser *parser);

void					token_error(t_token *token);

void					name_error(void);

void					comment_error(void);

void					label_error(t_label *label);

void					operator_error(t_token *token);

void					arg_type_error(t_op *op, int arg_num, t_token *token);

/*
** Utils
*/

void					int32_to_bytecode(char *data,
											int32_t pos,
											int32_t value,
											size_t size);

#endif
