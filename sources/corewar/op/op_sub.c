/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:50:03 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/30 20:53:35 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_sub(uint32_t cursor_id,
							int32_t r1_id,
							int32_t r2_id,
							int32_t r3_id)
{
	ft_printf("P %4d | sub r%d r%d r%d\n", cursor_id, r1_id, r2_id, r3_id);
}

void				op_sub(t_vm *vm, t_cursor *cursor)
{
	int32_t	r1_id;
	int32_t	r2_id;
	int32_t	r3_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r1_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	r2_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[INDEX(r1_id)] - cursor->reg[INDEX(r2_id)];
	cursor->carry = (t_bool)(!value);
	r3_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r3_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_sub(cursor->id, r1_id, r2_id, r3_id);
}
