/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:49:17 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/30 20:52:44 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_fork(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | fork %d (%d)\n",
										cursor->id,
										addr,
										cursor->pc + addr % IDX_MOD);
}

void				op_fork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	new = duplicate_cursor(cursor, addr % IDX_MOD);
	add_cursor(&(vm->cursors), new);
	vm->cursors_num++;
	if (vm->log & OP_LOG)
		log_fork(cursor, addr);
}
