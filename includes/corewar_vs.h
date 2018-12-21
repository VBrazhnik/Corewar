/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:22:10 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/21 15:53:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VS_H
# define COREWAR_VS_H

# include <ncurses.h>
# include <stdint.h>
# include "libft.h"
# include <time.h>

# define MIN_PLAYER_ID 1
# define MAX_PLAYER_ID 4
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
# define CYCLE_TO_WAIT			50
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

typedef struct s_map
{
	uint32_t		value;
	size_t		time_to_wait_live;
	size_t		time_to_wait;
}				t_map;

typedef struct	s_vs
{
	WINDOW		*win_arena;
	WINDOW		*win_info;
	WINDOW		*win_help;
	t_map		map[MEM_SIZE];
	size_t		last_per_live[MAX_PLAYERS];
	int32_t		control_button;
	clock_t 	time;
	char 		aff_symbol;
	int32_t 	aff_owner;
	t_bool		is_run;
	t_bool		display_help;
	int32_t		help_cursor_position;
	int32_t 	curr_cursor_position;
	size_t		total_lives_in_curr_per;
	size_t		total_lives_in_last_per;
	t_bool		time_delay;
	t_bool		end;
	int32_t		speed;
	t_bool		sounds;
	size_t		cariage_quant_delta;

}				t_vs;

#endif
