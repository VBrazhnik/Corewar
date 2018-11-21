/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:23:16 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/09 20:00:46 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_op.h"

void	op_live(t_vm **vm, t_cursor **cursor, t_op op)
{
	int32_t player_id;

	(void)op;
	(*cursor)->step += OP_CODE_LEN;
	player_id = bytecode_to_int32((*vm)->arena,
									(*cursor)->pc + (*cursor)->step, DIR_SIZE);
	((*cursor)->lives_num)++;
	if (player_id <= -1 && player_id >= -(MAX_PLAYERS))
	{
		if ((*vm)->players[INDEX(FT_ABS(player_id))])
		{
			(*vm)->players[INDEX(FT_ABS(player_id))]->last_live = (*vm)->cycles;
			(*vm)->players[INDEX(FT_ABS(player_id))]->lives_num++;
		}
	}
	(*cursor)->step += op.t_dir_size;
}
