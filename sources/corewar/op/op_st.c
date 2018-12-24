/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:31:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/12/24 16:46:56 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar_op.h"
#include "corewar_vs.h"

inline static void	log_st(uint32_t cursor_id, int32_t r_id, int32_t addr)
{
	ft_printf("P %4d | st r%d %d\n", cursor_id, r_id, addr);
}

inline static void	vs_st(t_vm *vm, t_cursor *cursor, int32_t addr)
{
	if (vm->vs)
		update_map(vm, cursor, cursor->pc + (addr % IDX_MOD), DIR_SIZE);
}

void				op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	r_value;
	int32_t	addr;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	r_value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[INDEX(addr)] = r_value;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = bytecode_to_int32(vm->arena,
							cursor->pc + cursor->step, IND_SIZE);
		int32_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD),
							r_value, DIR_SIZE);
		vs_st(vm, cursor, addr);
		cursor->step += IND_SIZE;
	}
	if (vm->log & OP_LOG)
		log_st(cursor->id, r_id, addr);
}
