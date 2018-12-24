/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/24 17:53:14 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VS_H

# define COREWAR_VS_H

# include "libft.h"
# include "op.h"
# include "corewar.h"
# include <ncurses.h>
# include <stdint.h>
# include <time.h>

# define MIN_PLAYER_ID			1
# define MAX_PLAYER_ID			4
# define HEIGHT					(MEM_SIZE / 64 + 4)
# define WIDTH					(64 * 3 + 5)
# define DEFAULT_CUSTOM_INDENT	7
# define WIDGET_LEN				(WIDTH / 4 + 4)
# define TAB_LEN				4
# define COLOR_GRAY				8
# define ZERO_BYTE_CURSOR(x)	(x == 0) ? (x = x + 9) : (x)
# define ZERO_CURSOR			9
# define GREEN_PLAYER			9
# define BLUE_PLAYER			10
# define RED_PLAYER				11
# define CYAN_PLAYER			12
# define GREEN_CURSOR			13
# define BLUE_CURSOR			14
# define RED_CURSOR				15
# define CYAN_CURSOR			16
# define GRAY_PLAYER			17
# define GRAY_CURSOR			18
# define LIVE_PAIR_GREEN		19
# define LIVE_PAIR_BLUE			20
# define LIVE_PAIR_RED			21
# define LIVE_PAIR_CYAN			22

/*
** Buttons
*/

# define ESC					27
# define SPACE					' '
# define SPEED_UP_1				'e'
# define SPEED_UP_10			'r'
# define SPEED_UP_100			't'
# define SPEED_DOWN_1			'q'
# define SPEED_DOWN_10			'a'
# define SPEED_DOWN_100			'z'
# define SPEED_DEFAULT			'd'
# define DISPLAY_HELP			'h'
# define MUSIC					'm'
# define PASS_ONE_CYCLE			's'

# define CYCLE_TO_WAIT			40
# define DEFAULT_SPEED			50
# define INDEX_CURSOR(X)		((X) + 4)
# define INDEX_PLAYER(X)		((X) - 4)

static unsigned short g_colors_players[15] = {
	COLOR_PAIR(GRAY_PLAYER),
	COLOR_PAIR(GREEN_PLAYER),
	COLOR_PAIR(BLUE_PLAYER),
	COLOR_PAIR(RED_PLAYER),
	COLOR_PAIR(CYAN_PLAYER),
	COLOR_PAIR(GREEN_CURSOR),
	COLOR_PAIR(BLUE_CURSOR),
	COLOR_PAIR(RED_CURSOR),
	COLOR_PAIR(CYAN_CURSOR),
	COLOR_PAIR(GRAY_CURSOR),
};

/*
** Map
*/

typedef struct		s_map
{
	int32_t			value;
	size_t			wait_cycles;
	size_t			wait_cycles_live;
}					t_map;

/*
** Visualizer
*/

typedef struct		s_vs
{
	WINDOW			*win_arena;
	WINDOW			*win_info;
	WINDOW			*win_help;
	t_map			map[MEM_SIZE];
	size_t			players_lives[MAX_PLAYERS];
	int32_t			button;
	clock_t			time;
	t_bool			is_run;
	int32_t			help_cursor_position;
	int32_t			cursor_pos;
	size_t			total_lives_in_curr_per;
	size_t			total_lives_in_last_per;
	t_bool			time_delay;
	char			aff_symbol;
	t_player		*aff_player;
	t_bool			sounds;
	t_bool			display_help;
	int32_t			speed;
}					t_vs;

/*
** Functions
*/

/*
** Init
*/

t_vs				*init_vs(void);

/*
** Execute
*/

void				exec_vs(t_vm *vm);

/*
** Configure
*/

void				configure_vs(t_vm *vm);

/*
** Draw
*/

void				draw(t_vm *vm);

void				draw_info(t_vm *vm);

void				draw_help(t_vm *vm);

void				draw_exec_status(t_vm *vm);

void				draw_sounds_status(t_vm *vm);

void				draw_help_status(t_vm *vm);

/*
** Cursor
*/

void				draw_cursor(t_vm *vm, t_cursor *cursor);

void				clear_cursor(t_vm *vm, t_cursor *cursor);

/*
** Colors
*/

void				init_colors(void);

uint32_t			check_attributes(t_vm *vm, t_map *attribute);

/*
** Widgets
*/

void				store_players_lives(t_vm *vm);

void				draw_live_breakdown(t_vm *vm,
										size_t total_live_in_per,
										char *period);

int32_t				calc_percent(double curr_lives, size_t total_lives);

size_t				calc_players_lives(t_vm *vm);

/*
** Sound
*/

void				play_death_sound(t_vm *vm);

void				play_winner_sound(t_vm *vm);

/*
** Free
*/

void				free_vs(t_vm *vm);

/*
** Utils
*/

void				clear_name(char *name);

clock_t				calc_time_delay(t_vm *vm);

void				update_map(t_vm *vm,
								t_cursor *cursor,
								int32_t addr,
								int32_t size);

#endif
