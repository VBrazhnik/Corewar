/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:49:19 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 14:49:19 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_ERROR_H

# define COREWAR_ERROR_H

# define ERR_PLAYER_INIT		"ERROR: Can\'t initialize player"

# define ERR_CURSOR_INIT		"ERROR: Can\'t initialize cursor"

# define ERR_VM_INIT			"ERROR: Can\'t initialize virtual machine"

# define ERR_OPEN_FILE			"ERROR: Can\'t open file with champion"

# define ERR_READ_FILE			"ERROR: Can\'t read file with champion"

# define ERR_INVALID_FILE		"ERROR: Invalid file with champion"

# define ERR_INVALID_MAGIC		"ERROR: Invalid magic header"

# define ERR_NO_NULL			"ERROR: No null control bytes"

# define ERR_STR_INIT			"ERROR: Can\'t initialize string"

# define ERR_CODE_INIT			"ERROR: Can\'t initialize string of code"

# define ERR_INVALID_CODE_SIZE	"ERROR: Invalid code size"

# define ERR_PLAYERS_NUM		"ERROR: Invalid number of players"

# define ERR_VS_INIT			"ERROR: Can\'t initialize visualiser"

#endif
