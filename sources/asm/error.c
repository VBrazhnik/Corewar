/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazhni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 02:12:27 by vbrazhni          #+#    #+#             */
/*   Updated: 2018/12/13 05:12:22 by vbrazhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"

void	lexical_error(t_parser *parser)
{
	ft_dprintf(2, "Lexical error at [%03u:%03u]\n",
													parser->line,
													parser->column);
	exit(1);
}

void	token_error(t_token *token)
{
	ft_dprintf(2, "Unexpected token \"%s\" %s at [%03u:%03u]\n",
														token->content,
														g_type[token->type],
														token->line,
														token->column);
	exit(1);
}

void	name_error(void)
{
	ft_dprintf(2, "Champion name too long (Max length %u)\n",
															PROG_NAME_LENGTH);
	exit(1);
}

void	comment_error(void)
{
	ft_dprintf(2, "Champion comment too long (Max length %u)\n",
																COMMENT_LENGTH);
	exit(1);
}

void	label_error(t_label *label)
{
	t_mention	*mention;

	ft_dprintf(2, "Undeclared label \"%s\" is mentioned at:\n", label->name);
	mention = label->mentions;
	while (mention)
	{
		ft_dprintf(2, "\t— [%03u:%03u]\n", mention->line, mention->column);
		mention = mention->next;
	}
	exit(1);
}

void	operator_error(char *name)
{
	ft_dprintf(2, "Unknown operator \"%s\"\n", name);
	exit(1);
}

void	arg_type_error(t_op *op, int arg_num, t_parser *parser)
{
	ft_dprintf(2, "Invalid type of parameter #%d for instruction \"%s\""\
													" at [%03u:%03u]\n",
															arg_num + 1,
															op->name,
															parser->line,
															parser->column);
	exit(1);
}
