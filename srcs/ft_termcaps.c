/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:52:45 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/18 14:34:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

static void	disable_raw_mode(struct termios *og_raw)
{
	tcsetattr(STDIN_FILENO, TCSANOW, og_raw);
}

static int	init_raw(struct termios *og_raw)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, og_raw) == -1)
		return (0);
	raw = *og_raw;
	raw.c_lflag &= ~(ICANON | ECHO | IEXTEN | ISIG);
	raw.c_iflag &= ~(IXON | BRKINT);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
		return (0);
	return (1);
}

static void	input_cycle(char *input, int *bytes, int *cur, int *ch)
{
	int		quote;

	quote = 0;
	while (*ch != -1)
	{
		*ch = get_input();
		if (*ch == D_QUOTE || *ch == S_QUOTE)
			quote_count(&quote, ch);
		else if (*ch == ENTER && !quote)
			return ;
		else if (*ch == CTRL_D && *cur < *bytes)
			delete(input, bytes, cur, &quote);
		else if (*ch == BACKSPACE && *cur > 0)
			backspace(input, bytes, cur, &quote);
		if (*ch == ESCAPE)
			esc_parse(input, bytes, cur, ch);
		if (ft_isprint(*ch) || (*ch == ENTER && quote))
		{
			char_print(input, bytes, cur, *ch);
			if (*ch == ENTER && quote)
				write(1, "> ", 2);
		}
	}
}

int	ft_termcaps(char *input)
{
	int				ch;
	int				bytes;
	int				cursor;
	struct termios	og_raw;

	ch = 0;
	bytes = 0;
	cursor = 0;
	ft_bzero(input, BUFF_SIZE);
	if (!init_raw(&og_raw))
	{
		ft_putstr_fd("error, raw mode\n", STDERR_FILENO);
		exit(1);
	}
	input_cycle(input, &bytes, &cursor, &ch);
	if (ch == -1)
		ft_putstr_fd("error, read\n", STDERR_FILENO);
	disable_raw_mode(&og_raw);
	write(1, "\n", 1);
	return (0);
}
