/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:05:53 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/14 09:01:36 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cursor_right(int *cursor)
{
	if (cursor)
		cursor[0]++;
	write(1, "\033[1C", 4);
}

void	cursor_left(int *cursor)
{
	if (cursor)
		cursor[0]--;
	write(1, "\033[1D", 4);
}

void	alt_mv_left(int *cursor, char *input)
{
	int		b;
	char	*tofree;

	b = 0;
	tofree = NULL;
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
		tofree = ft_itoa(b);
		write(1, tofree, ft_strlen(tofree));
		ft_strdel(&tofree);
		write(1, "D", 1);
	}
}

void	alt_mv_right(int *cursor, char *input, int *bytes)
{
	int		b;
	char	*tofree;

	b = 0;
	tofree = NULL;
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
		tofree = ft_itoa(b);
		write(1, tofree, ft_strlen(tofree));
		ft_strdel(&tofree);
		write(1, "C", 1);
	}
}
