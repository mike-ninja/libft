/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:52:49 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/19 08:10:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

int	get_input(void)
{
	int	c;

	c = 0;
	read(STDIN_FILENO, &c, 1);
	return (c);
}

void	print_trail(char *input, int cursor)
{
	term_cap("sc");
	ft_putstr(&input[cursor]);
	term_cap("rc");
}

void	clear_trail(void)
{
	term_cap("ce");
}

void	quote_count(t_info *info)
{
	if (!info->quote_qty)
	{
		info->quote = info->ch;
		info->quote_qty++;
	}
	else if (info->quote == info->ch)
		info->quote_qty--;
}

void	term_cap(char *capability)
{
	char		*str;
	char		*buf;

	str = NULL;
	buf = NULL;
	tgetent(buf, getenv("TERM"));
	str = tgetstr(capability, NULL);
	if (str)
		write(1, str, ft_strlen(str));
}
