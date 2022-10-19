/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:52:45 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/19 09:38:58 by mbarutel         ###   ########.fr       */
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

static void	input_cycle(char *input, t_info *info)
{
	while (info->ch != -1)
	{
		info->ch = get_input();
		if (info->ch == D_QUOTE || info->ch == S_QUOTE)
			quote_count(info);
		else if (info->ch == ENTER && !info->quote_qty)
			return ;
		else if (info->ch == CTRL_D && info->cursor < info->bytes)
			delete(input, info);
		else if (info->ch == BACKSPACE && info->cursor > 0)
			backspace(input, info);
		if (info->ch == ESCAPE)
			esc_parse(input, info);
		if (ft_isprint(info->ch) || (info->ch == ENTER && info->quote_qty))
		{
			char_print(input, info);
			if (info->ch == ENTER && info->quote_qty)
				write(1, "> ", 2);
		}
		if (info->bytes == (BUFF_SIZE - 1))
			break ;
	}
}

static void	init_info(t_info *info)
{
	info->ch = 0;
	info->bytes = 0;
	info->quote = 0;
	info->cursor = 0;
	info->quote_qty = 0;
}

int	ft_termcaps(char *input)
{
	t_info			info[1];
	struct termios	og_raw;

	init_info(info);
	ft_bzero(input, BUFF_SIZE);
	if (!init_raw(&og_raw))
	{
		ft_putstr_fd("error, raw mode\n", STDERR_FILENO);
		exit(1);
	}
	input_cycle(input, info);
	if (info->ch == -1)
		ft_putstr_fd("error, read\n", STDERR_FILENO);
	disable_raw_mode(&og_raw);
	write(1, "\n", 1);
	return (0);
}
