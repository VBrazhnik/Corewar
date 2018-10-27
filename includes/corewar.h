/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:23:28 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/10/24 14:23:29 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H

# define COREWAR_H

# include "op.h"
# include "vs.h"
# include "libft.h"
# include <stdint.h>

/*
** Player
*/

/*
** id        — id number of player
** name      — champion's name
** comment   — champion's comment
** code_size — size of champion's executable code
** code      — champion's executable code
** last_live — cycle's number, on which player was assigned as alive last time
** lives_num — number of reports that player is alive during cycles_to_die
** next      — pointer to the next player
*/

typedef struct			s_player
{
	int32_t				id;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
	size_t				last_live;
	size_t				lives_num;
	struct s_player		*next;
}						t_player;

/*
** Cursor
*/

/*
** is_alive       — flag which reports that cursor was assigned as alive
**                  during cycles_to_die
** carry          — special flag
** op_code        — operator's code that is placed under cursor
** cycles_to_exec — number of cycles that remains to wait
**                  before operator execution
** pos            — address of current position at memory
** pc             — address of the next operator to execute at memory
** reg            — registers
** next           — pointer to the next cursor
*/

typedef struct			s_cursor
{
	t_bool				is_alive;
	t_bool				carry;
	uint8_t				op_code;
	int					cycles_to_exec;
	uint32_t			pc;
	int32_t				reg[REG_NUMBER];
	struct s_cursor		*next;
}						t_cursor;

/*
** Virtual machine
*/

/*
** arena         — memory where players are fighting
** players       — list of players
** players_num   — number of players
** last_alive    — pointer to the last player that was assigned as alive
** cursors       — list of cursors
** cursors_num   — number of cursors
** cycles        — number of cycles that was passed after start
** cycles_to_die — game parameter
** checks_num    — game parameter
** vs            — visualizer
** dump          — cycle's number after which dump will be created
** display_aff   — flag that reports display output of aff operator or not
** log           — number that reports about log level.
**                 If log is assigned as -1, it means that log doesn't display.
*/

typedef struct			s_vm
{
	uint8_t				arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS];
	size_t				players_num;
	t_player			*last_alive;
	t_cursor			*cursors;
	size_t				cursors_num;
	size_t				cycles;
	ssize_t				cycles_to_die;
	size_t				checks_num;
	t_vs				*vs;
	int					dump;
	t_bool				display_aff;
	uint8_t				log;
}						t_vm;

/*
** Operator
*/

/*
** name            — operator's name
** code            — operator's code
** args_num        — number of arguments
** args_types_code — flag which reports that operator has code of types
** args_types      — types of each argument
** modify_carry    — flag which reports that operator modifies carry
** t_dir_size      — size of T_DIR agrument.
** cycles          — cycles to execution of operator
** func            — pointer to function
*/

typedef struct			s_op
{
	char				*name;
	uint8_t				code;
	uint8_t				args_num;
	t_bool				args_types_code;
	uint8_t				args_types[3];
	t_bool				modify_carry;
	uint8_t				t_dir_size;
	uint32_t			cycles;
	void				*func;
}						t_op;

static t_op				g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 4,
		.cycles = 10,
		.func = NULL
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 5,
		.func = NULL
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = false,
		.t_dir_size = 0,
		.cycles = 5,
		.func = NULL
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 0,
		.cycles = 10,
		.func = NULL
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = true,
		.t_dir_size = 0,
		.cycles = 10,
		.func = NULL
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = NULL
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = NULL
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 6,
		.func = NULL
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 20,
		.func = NULL
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = NULL
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 25,
		.func = NULL
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 800,
		.func = NULL
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = true,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = true,
		.t_dir_size = 4,
		.cycles = 10,
		.func = NULL
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = true,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = true,
		.t_dir_size = 2,
		.cycles = 50,
		.func = NULL
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = false,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = false,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = NULL
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = true,
		.args_types = {T_REG, 0, 0},
		.modify_carry = false,
		.t_dir_size = 0,
		.cycles = 2,
		.func = NULL
	}
};

/*
** Functions
*/

/*
** Init
*/

t_player				*init_player(int id);

t_cursor				*init_cursor(int32_t id,
									uint32_t pc,
									uint8_t op_code,
									int cycles_to_exec);

t_vm					*init_vm(void);

void					init_arena(t_vm *vm);

/*
** Parse
*/

void					parse_args(int argc, char **argv, t_vm *vm);

void					parse_vs_flag(int *argc, char ***argv, t_vm *vm);

void					parse_dump_flag(int *argc, char ***argv, t_vm *vm);

void					parse_aff_flag(int *argc, char ***argv, t_vm *vm);

void					parse_log_flag(int *argc, char ***argv, t_vm *vm);

t_player				*parse_champion(char *filename, int num);

/*
** Find
*/

t_player				*find_player(t_player *list, int32_t id);

/*
** Print
*/

void					print_help(void);

void					print_arena(uint8_t *arena);

/*
** Utils
*/

void					terminate(char *s);

int32_t					bytecode_to_int32(const uint8_t *bytecode, size_t size);

t_bool					is_filename(const char *filename);

#endif
