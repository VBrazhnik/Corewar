/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/25 04:13:09 by vbrazhni         ###   ########.fr       */
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

/*
** Dimensions
*/

# define HEIGHT					(MEM_SIZE / 64 + 4)
# define WIDTH					(64 * 3 + 5)
# define DEFAULT_CUSTOM_INDENT	7
# define WIDGET_LEN				(WIDTH / 4 + 4)
# define TAB_LEN				4

/*
** Color
*/

# define COLOR_GRAY				8

/*
** Color pairs
*/

# define GRAY					9
# define GREEN					10
# define YELLOW					11
# define RED					12
# define CYAN					13
# define GRAY_CURSOR			14
# define GREEN_CURSOR			15
# define YELLOW_CURSOR			16
# define RED_CURSOR				17
# define CYAN_CURSOR			18
# define LIVE_GREEN				19
# define LIVE_YELLOW			20
# define LIVE_RED				21
# define LIVE_CYAN				22

/*
** Buttons
*/

# define ESC					27
# define SPACE					' '
# define SPEED_UP_1				'r'
# define SPEED_UP_10			't'
# define SPEED_UP_100			'y'
# define SPEED_DOWN_1			'e'
# define SPEED_DOWN_10			'w'
# define SPEED_DOWN_100			'q'
# define SPEED_DEFAULT			'd'
# define DISPLAY_HELP			'h'
# define MUSIC					'm'
# define PASS_ONE_CYCLE			's'

# define CYCLE_TO_WAIT			49
# define DEFAULT_SPEED			50
# define INDEX_CURSOR(X)		((X) + 5)
# define INDEX_PLAYER(X)		((X) - 5)

static unsigned short g_colors_players[15] = {
	COLOR_PAIR(GRAY),
	COLOR_PAIR(GREEN),
	COLOR_PAIR(YELLOW),
	COLOR_PAIR(RED),
	COLOR_PAIR(CYAN),
	COLOR_PAIR(GRAY_CURSOR),
	COLOR_PAIR(GREEN_CURSOR),
	COLOR_PAIR(YELLOW_CURSOR),
	COLOR_PAIR(RED_CURSOR),
	COLOR_PAIR(CYAN_CURSOR)
};

/*
** Map
*/

typedef struct		s_map
{
	int32_t			value;
	ssize_t			wait_cycles_store;
	ssize_t			wait_cycles_live;
	t_player		*player_live;
}					t_map;

/*
** Visualizer
*/

typedef struct		s_vs
{
	t_bool			is_running;
	WINDOW			*win_arena;
	WINDOW			*win_info;
	WINDOW			*win_help;
	t_map			map[MEM_SIZE];
	size_t			players_lives[MAX_PLAYERS];
	int32_t			button;
	clock_t			time;
	int32_t			cursor_pos;
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

void				draw_current_lives_bar(t_vm *vm);

void				draw_previous_lives_bar(t_vm *vm);

/*
** Cursor
*/

void				draw_cursor(t_vm *vm, t_cursor *cursor);

void				clear_cursor(t_vm *vm, t_cursor *cursor);

/*
** Colors
*/

void				init_colors(void);

uint32_t			get_attribute(t_vm *vm, t_map *attribute, ssize_t cycles);

/*
** Widgets
*/

void				store_players_lives(t_vm *vm);

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
