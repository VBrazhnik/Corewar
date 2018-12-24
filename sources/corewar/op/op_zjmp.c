/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:17:29 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/23 20:47:30 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"
#include "corewar_vs.h"

inline static void	log_zjmp(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | zjmp %d %s\n",
									cursor->id,
									addr,
									(cursor->carry) ? "OK" : "FAILED");
}

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	if (cursor->carry)
	{
		if (vm->vs)
			clear_cursor(vm, cursor);
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		if (vm->vs)
			draw_cursor(vm, cursor);
		cursor->step = 0;
	}
	if (vm->log & OP_LOG)
		log_zjmp(cursor, addr);
}
