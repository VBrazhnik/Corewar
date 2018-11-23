/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:33:56 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/12 17:24:55 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_ldi(t_cursor *cursor,
				int32_t addr_1,
				int32_t addr_2,
				int32_t reg_id)
{
	ft_printf("P %4d | ldi %d %d r%d\n", cursor->id, addr_1, addr_2, reg_id);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
									addr_1,
									addr_2,
									addr_1 + addr_2,
									cursor->pc + (addr_1 + addr_2) % IDX_MOD);
}

void				op_ldi(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr_1;
	int32_t		addr_2;
	int32_t		reg_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	addr_1 = get_op_arg(vm, cursor, 1, true);
	addr_2 = get_op_arg(vm, cursor, 2, true);
	reg_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(reg_id)] = bytecode_to_int32(vm->arena,
				(cursor->pc + ((addr_1 + addr_2) % IDX_MOD)), DIR_SIZE);
	cursor->step += REG_LEN;
	if (vm->log & OP_LEVEL)
		log_ldi(cursor, addr_1, addr_2, reg_id);
}
