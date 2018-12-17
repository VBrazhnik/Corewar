/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:38:06 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/16 14:38:06 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERROR_H

# define ASM_ERROR_H

# define ERR_STR_INIT			"ERROR: Can\'t initialize string"

# define ERR_PARSER_INIT		"ERROR: Can\'t initialize parser"

# define ERR_TOKEN_INIT			"ERROR: Can\'t initialize token"

# define ERR_LABEL_INIT			"ERROR: Can\'t initialize label"

# define ERR_MENTION_INIT		"ERROR: Can\'t initialize mention"

# define ERR_STATEMENT_INIT		"ERROR: Can\'t initialize statement"

# define ERR_OPEN_FILE			"ERROR: Can\'t open file with champion"

# define ERR_READ_FILE			"ERROR: Can\'t read file with champion"

# define ERR_CREATE_FILE		"ERROR: Can\'t create file"

# define ERR_INVALID_FILE		"ERROR: Invalid file with champion"

# define ERR_INVALID_MAGIC		"ERROR: Invalid magic header"

# define ERR_NO_NULL			"ERROR: No null control bytes"

# define ERR_CODE_INIT			"ERROR: Can\'t initialize string of code"

# define ERR_INVALID_CODE_SIZE	"ERROR: Invalid code size"

#endif
