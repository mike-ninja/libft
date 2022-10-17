/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 07:52:49 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/17 12:04:25 by mbarutel         ###   ########.fr       */
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

void	quote_count(int *quote, int *c)
{
	if (!*quote)
		*quote = *c;
	else if (*quote == *c)
		*quote = 0;
}

void	term_cap(char *capability)
{
	char		*buf;
	char		*str;
	char		*term;
	str = NULL;
	buf = (char *)ft_memalloc(sizeof(*buf));
	term = getenv("TERM");
	tgetent(buf, term);
	str = tgetstr(capability, NULL);
	if (str)
		write(1, str, ft_strlen(str));
}
