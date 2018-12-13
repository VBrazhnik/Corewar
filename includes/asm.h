/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by amedvedi          #+#    #+#             */
/*   Updated: 2018/12/13 05:00:47 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include "asm_op.h"

# define BUFF_SIZE 2048

# define MAX_STMT_SIZE 20

# define REG_CHAR 'r'

/*
** Token
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

typedef struct			s_token
{
	char				*content;
	t_type				type;
	unsigned			line;
	unsigned			column;
	struct s_token		*next;
}						t_token;

/*
** Mention
*/

/*
** pos    — number of byte where argument-label is placed
** op_pos — number of byte where operator is placed
** size   — number of bytes which store a value at pos
** next   — pointer to the next mention
*/

typedef struct			s_mention
{
	unsigned			line;
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
** line     — line where label is placed in asm file
** column   — column where label is placed in asm file
** pos      — number of byte on which argument-label point
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
** Assembler
*/

typedef struct			s_parser
{
	int					fd;
	unsigned			line;
	unsigned			column;
	t_token				*tokens;
	int32_t				pos;
	int32_t				op_pos;
	char				*name;
	char				*comment;
	char				*code;
	t_label				*labels;
}						t_parser;

/*
** Init
*/

t_parser				*init_parser(int fd);

t_token					*init_token(t_parser *parser, t_type type);

t_label					*init_label(char *name, int op_pos);

t_mention				*init_mention(t_parser *parser, size_t size);

/*
** Parse
*/

int						get_row(int fd, char **line);

void					parse_asm(t_parser *parser);

/*
** Parse Utils
*/

t_bool					is_delimiter(int c);

t_bool					is_register(const char *arg);

char					*get_token_content(t_parser *parser,
											const char *line,
											unsigned start);

void					update_parser_position(t_parser *parser,
											const char *line);

/*
** Skip
*/

void					skip_whitespaces(t_parser *parser, const char *line);

void					skip_comment(t_parser *parser, const char *line);

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

void					process_code(t_parser *parser, t_token **current);

int8_t					process_arg(t_parser *parser,
									t_token **current,
									t_op *op,
									int arg_num);

/*
** Process Utils
*/

void					update_code_buff(t_parser *parser, size_t *code_size);

t_op					*get_op(char *name);

void					update_types_code(int8_t *types_code,
										int8_t type,
										int arg_num);

/*
** Error
*/

void					lexical_error(t_parser *parser);

void					token_error(t_token *token);

void					name_error(void);

void					comment_error(void);

void					label_error(t_label *label);

void					operator_error(char *name);

void					arg_type_error(t_op *op, int arg_num, t_parser *parser);

/*
** Print
*/

void					print_help(void);

/*
** Write
*/

void					write_file(int fd, t_parser *parser);

/*
** Free
*/

void					free_parser(t_parser **parser);

/*
** Filename
*/

t_bool					is_filename(const char *filename, const char *ext);

char					*replace_extension(char *filename,
											char *old,
											char *new);

/*
** Utils
*/

void					terminate(char *s);

void					int32_to_bytecode(char *data,
											int32_t i,
											int32_t value,
											size_t size);

t_bool					is_terminator(int c);

int						is_whitespace(int c);

#endif
