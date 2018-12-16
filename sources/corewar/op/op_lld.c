/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:46:46 by ablizniu          #+#    #+#             */
/*   Updated: 2018/11/30 20:53:13 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"

inline static void	log_lld(uint32_t cursor_id, int32_t value, int32_t r_id)
{
	ft_printf("P %4d | lld %d r%d\n", cursor_id, value, r_id);
}

void				op_lld(t_vm *vm, t_cursor *cursor)
{
	int32_t	value;
	int32_t	r_id;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, false);
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_lld(cursor->id, value, r_id);
}
