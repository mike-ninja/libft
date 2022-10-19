/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:23:01 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/19 09:29:48 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

void	delete(char *input, t_info *info)
{
	if (input[info->cursor - 1] == info->quote)
		info->quote_qty++;
	deletion_shift(input, &info->bytes, &info->cursor, DEL);
	clear_trail();
	print_trail(input, info->cursor);
}

void	backspace(char *input, t_info *info)
{
	term_cap("le");
	clear_trail();
	if (input[info->cursor - 1] == info->quote)
		info->quote_qty++;
	if (info->cursor == info->bytes)
	{
		info->bytes--;
		info->cursor--;
		input[info->cursor] = '\0';
	}
	else
		deletion_shift(input, &info->bytes, &info->cursor, BCK);
	if (input[info->cursor])
		print_trail(input, info->cursor);
}

void	cursor_mv(int *bytes, int *cur, int c)
{
	if (c == K_LEFT && *cur)
		cur_left(cur);
	if (c == K_RIGHT && (*cur < *bytes))
		cur_right(cur);
}

void	char_print(char *input, t_info *info)
{
	write(1, &info->ch, 1);
	if (input[info->cursor])
		insertion_shift(input, &info->bytes, info->cursor);
	input[info->cursor++] = info->ch;
	if (input[info->cursor])
		print_trail(input, info->cursor);
	info->bytes++;
}
