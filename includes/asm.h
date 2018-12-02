/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by amedvedi          #+#    #+#             */
/*   Updated: 2018/06/29 02:11:13 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdio.h>

/*
** Bot name and command length
** 16: 4 - magic header, 4 - null, 4 - bot size, 4 - null
** 2192
*/

# define NAME_COMM_LENGTH	(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

# define REG_CHAR 'r'

/*
** Label mention list
** idx ------position at the file
** size -----size of the label (4 or 2)
** value ----the given value to calculate the distance
*/

typedef struct			s_replace
{
	int					idx;
	int					size;
	int					value;
	struct s_replace	*next;
}						t_replace;

/*
** Labels list
** name ---------name of the label
** initialized ----indicator if the label was initialized
** pos ----------position at the file in the instruction section
** x ------------column position at file
** y ------------row position at file
** mention ------list of the mentions of the label from instructions
*/

typedef struct			s_lbl
{
	char				*name;
	int					initialized;
	int					pos;
	int					x;
	int					y;
	t_replace			*mention;
	struct s_lbl		*next;
}						t_lbl;

/*
** Main structure
** i -----------length of the whole given file
** pos ---------row position at file
** pos_x -------column position at file
** fd ----------file descriptor
** str ---------line from gnl
** r_str -------array used to save important parts from str
** file_name ----name for new .cor file
** data --------an array containing all written hex code
** label -------array containing a list of labels
*/

typedef struct			s_val
{
	int					i;
	int					pos_y;
	int					pos_x;
	int					fd;
	char				*str;
	char				*r_str;
	char				*file_name;
	char				*data;
	t_lbl				*label;
}						t_val;

/*
** Libft_functions
*/

int						ft_skip_whitespaces(char *str, int i);
int						ft_iswhitespace(int c);
int						ft_strchri(const char *s, int c);
int						ft_strcmpi(const char *s1, const char *s2);

/*
** Validating header
*/

void					read_bot_name_comm(t_val *assm, int i, int ret);
void					check_comm(t_val *assm, int i);

/*
** Validating instruction name and parsing
*/

void					read_bot_op(t_val *assm);

/*
** All instruction parsing
** check_dir - 				live, zjump, fork, lfork
** check_two_reg -  		ld, lld
** check_three_reg - 		and, or, xor
** check_reg - 				sub, add
** check_three_two_reg - 	ldi, lldi
** in own files - 			st, sti, aff
*/

void					check_live(t_val *assm, int i);
void					check_zjmp(t_val *assm, int i);
void					check_fork(t_val *assm, int i);
void					check_lfork(t_val *assm, int i);

/*
** -------------------------------------------check_two_reg
*/

void					check_ld(t_val *assm, int i);
void					check_lld(t_val *assm, int i);

/*
** -------------------------------------------check_three_reg
*/

void					check_and(t_val *assm, int i);
void					check_or(t_val *assm, int i);
void					check_xor(t_val *assm, int i);

/*
** -------------------------------------------check_reg
*/

void					check_sub(t_val *assm, int i);
void					check_add(t_val *assm, int i);

/*
** -------------------------------------------check_three_two_reg
*/

void					check_ldi(t_val *assm, int i);
void					check_lldi(t_val *assm, int i);

/*
** -------------------------------------------own files
*/

void					check_st(t_val *assm, int i);
void					check_sti(t_val *assm, int i);
void					check_aff(t_val *assm, int i);

/*
** Validating arguments in instruction
*/

int						get_type(char c, int *codage);
int						check_all_arg(t_val *assm, int i, int pos, int *codage);
int						check_reg_dir(t_val *assm, int i, int pos, int *codage);
int						check_dir_ind(t_val *assm, int i, int pos, int *codage);

/*
** Argument validation
*/

void					args_amount(t_val *assm, char *str, int nbr, int w);
int						reg_arg(t_val *assm, char *str, int i, int w);
int						dir_arg(t_val *assm, char *str, int i, int w);
int						ind_arg(t_val *assm, char *str, int i, int w);
int						skip_comma(t_val *assm, int i, char *error, int w);

/*
** Getting argument information
*/

int						get_arg(t_val *assm, int i, int size, int octet);
int						get_size(int dir_size, int type, int mode);

/*
** Minimized parsing of first and second argument
*/

int						get_arg_first_2(t_val *assm, int i, int codage,
										int i_pos);
int						get_arg_second_2(t_val *assm, int i, int codage,
										int i_pos);
int						get_arg_first_4(t_val *assm, int i, int codage,
										int i_pos);
int						get_arg_second_4(t_val *assm, int i, int codage,
										int i_pos);

/*
** Label operations
*/

int						read_label(t_val *assm, int init, int pc, int size);
void					create_label(t_val *assm, t_lbl **tmp, int pc,
									int size);
void					upd_label(t_val *assm, t_lbl **tmp, int pc, int size);
void					place_num(t_val *assm, int start, int i);

/*
** Error
*/

void					print_error(t_val *assm, char *str);
void					local_error(t_val *assm, char *msg, int what);
void					print_error_label(t_val *assm, char *msg, int x, int y);

/*
** Free
*/

void					free_asm(t_val *assm);

/*
** Final preparations
*/

void					place_labels(t_val *assm);
void					place_size(t_val *assm);
void					create_file(t_val *assm);

#endif
