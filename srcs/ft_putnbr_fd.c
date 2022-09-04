/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:06:08 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:34:02 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_putnbr_fd:
**	: Outputs the integer n to the file descriptor fd.
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (n > -2147483648)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			n = n % 10;
		}
		if (n < 10)
			ft_putchar_fd((n + '0'), fd);
	}
	else
		ft_putstr_fd("-2147483648", fd);
}
