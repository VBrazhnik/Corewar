/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:48:59 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/11/09 22:46:52 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(0);
}

t_bool	is_filename(const char *filename)
{
	if (filename && ft_strlen(filename) >= 4)
		return (!ft_strcmp((filename + ft_strlen(filename) - 4), ".cor"));
	else
		return (false);
}

int8_t	get_byte(t_vm **vm, int32_t pc, int32_t step)
{
	return ((*vm)->arena[calc_addr(pc + step)]);
}

int32_t	bytecode_to_int32_ptr(const uint8_t *bytecode, size_t size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int32_t	calc_addr(int32_t addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}

int32_t	bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

void	int32_to_bytecode(uint8_t *arena, int32_t addr, int32_t value,
																int32_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		arena[calc_addr(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}
