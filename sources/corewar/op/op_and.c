/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:33:19 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/30 20:52:39 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_and(uint32_t cursor_id,
							int32_t value_1,
							int32_t value_2,
							int32_t r_id)
{
	ft_printf("P %4d | and %d %d r%d\n", cursor_id, value_1, value_2, r_id);
}

void				op_and(t_vm *vm, t_cursor *cursor)
{
	int32_t	value_1;
	int32_t	value_2;
	int32_t	value;
	int32_t	r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	value_1 = get_op_arg(vm, cursor, 1, true);
	value_2 = get_op_arg(vm, cursor, 2, true);
	value = value_1 & value_2;
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_and(cursor->id, value_1, value_2, r_id);
}
