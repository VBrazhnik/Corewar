/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:17:29 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/13 15:14:20 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_zjmp(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | zjmp %d %s\n",
									cursor->id,
									addr,
									(cursor->carry) ? "OK" : "FAILED");
}

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	if (cursor->carry)
	{
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		cursor->step = 0;
	}
	if (vm->log & OP_LEVEL)
		log_zjmp(cursor, addr);
}
