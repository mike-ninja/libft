/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:05:53 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/18 15:28:50 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

void	cur_right(int *cursor)
{
	cursor[0]++;
	term_cap("nd");
}

void	cur_left(int *cursor)
{
	cursor[0]--;
	term_cap("le");
}

void	alt_mv_left(int *cursor, char *input)
{
	int	b;

	b = 0;
	while (cursor[0] > 0 && ft_iswhitespace(input[cursor[0] - 1]))
	{
		b++;
		cursor[0]--;
	}
	while (cursor[0] > 0 && !ft_iswhitespace(input[cursor[0] - 1]))
	{
		b++;
		cursor[0]--;
	}
	if (b)
	{
		write(1, "\033[", 2);
		ft_putnbr(b);
		write(1, "D", 1);
	}
}

void	alt_mv_right(int *cursor, char *input, int *bytes)
{
	int	b;

	b = 0;
	while (cursor[0] < *bytes && ft_iswhitespace(input[cursor[0]]))
	{
		b++;
		cursor[0]++;
	}
	while (cursor[0] < *bytes && !ft_iswhitespace(input[cursor[0]]))
	{
		b++;
		cursor[0]++;
	}
	if (b)
	{
		write(1, "\033[", 2);
		ft_putnbr(b);
		write(1, "C", 1);
	}
}
