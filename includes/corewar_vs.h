/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2019/01/03 06:39:39 by vbrazhni         ###   ########.fr       */
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
# define DEFAULT_INDENT			5
# define BAR_LENGTH				50
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

# define CYCLE_TO_WAIT			50
# define DEFAULT_SPEED			50
# define INDEX_CURSOR(X)		((X) + 5)
# define INDEX_PLAYER(X)		((X) - 5)

static int g_colors_players[15] = {
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
** Attribute
*/

/*
** index             — index of attribute
** wait_cycles_store — cycles to wait for st and sti operators
** wait_cycles_live  — cycles to wait for live operator
** player_live       — pointer to player which executed live operator
*/

typedef struct		s_attr
{
	int32_t			index;
	ssize_t			wait_cycles_store;
	ssize_t			wait_cycles_live;
	t_player		*player_live;
}					t_attr;

/*
** Visualizer
*/

/*
** is_running    — status of corewar execution (is running or paused)
** speed         — speed of execution (cycles per second)
** win_arena     — window of arena
** win_info      — window of info bar
** win_help      — window of help menu
** cursor_pos    — position of cursor that draws at windows
** map           — map of attributes
** button        — button which was pressed
** time          — time stamp
** aff_symbol    — symbol that aff operator printed
** aff_player    — player which executed aff operator
** sounds        — sounds are on/off
** display_help  — help menu is displayed, or not?
*/

typedef struct		s_vs
{
	t_bool			is_running;
	int				speed;
	WINDOW			*win_arena;
	WINDOW			*win_info;
	WINDOW			*win_help;
	int				cursor_pos;
	t_attr			map[MEM_SIZE];
	int				button;
	clock_t			time;
	char			aff_symbol;
	t_player		*aff_player;
	t_bool			sounds;
	t_bool			display_help;
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
** Colors
*/

void				init_colors(void);

int					get_attribute(t_vm *vm, t_attr *attribute, ssize_t cycles);

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
** Bar
*/

void				draw_lives_bar(t_vm *vm, t_bool current);

/*
** Sound
*/

void				play_death_sound(t_vm *vm);

void				play_victory_sound(t_vm *vm);

/*
** Free
*/

void				free_vs(t_vs **vs);

/*
** Operators' Utils
*/

void				update_map(t_vm *vm,
								t_cursor *cursor,
								int32_t addr,
								int32_t size);

/*
** Utils
*/

void				clear_name(char *name);

clock_t				calc_time_delay(t_vm *vm);

#endif
