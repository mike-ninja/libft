/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:23:01 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/18 14:15:12 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

void	delete(char *input, int *bytes, int *cur, int *qoute)
{
	if (input[cur[0] - 1] == '\'' || input[cur[0] - 1] == '"')
		qoute[0] = 0;
	deletion_shift(input, bytes, cur, DEL);
	clear_trail();
	print_trail(input, *cur);
}

void	backspace(char *input, int *bytes, int *cur, int *qoute)
{
	term_cap("le");
	clear_trail();
	if (input[cur[0] - 1] == '\'' || input[cur[0] - 1] == '"')
		qoute[0] = 0;
	if (*cur == *bytes)
	{
		bytes[0]--;
		cur[0]--;
		input[*cur] = '\0';
	}
	else
		deletion_shift(input, bytes, cur, BCK);
	if (input[*cur])
		print_trail(input, *cur);
}

void	cursor_mv(int *bytes, int *cur, int c)
{
	if (c == K_LEFT && *cur)
		cur_left(cur);
	if (c == K_RIGHT && (*cur < *bytes))
		cur_right(cur);
}

void	char_print(char *input, int *bytes, int *cur, int c)
{
	write(1, &c, 1);
	if (input[*cur])
		insertion_shift(input, bytes, *cur);
	input[cur[0]++] = c;
	if (input[*cur])
		print_trail(input, *cur);
	bytes[0]++;
}
