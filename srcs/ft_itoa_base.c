/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:32:26 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/12 13:03:42 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static char	ft_char_val(unsigned int val)
{
	char	ret;

	if (val >= 10)
		ret = (val - 10) + 'a';
	else
		ret = val + '0';
	return (ret);
}

static int	ft_deci_len(unsigned int val, int base)
{
	int	len;

	len = 0;
	while (val != 0)
	{
		len++;
		val /= base;
	}
	return (len);
}

/*
**	ft_itoa_base:
**	: Takes in a value and converts it to string based on base.
*/
char	*ft_itoa_base(int value, int base)
{
	int				len;
	unsigned int	tmp;
	char			*ret;

	if (value < 0 && base == 10)
		tmp = value * -1;
	else
		tmp = (unsigned int)value;
	len = ft_deci_len(tmp, base);
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		ret[len] = '\0';
		while (--len >= 0)
		{
			ret[len] = ft_char_val(tmp % base);
			tmp /= base;
		}
		return (ret);
	}
	return (NULL);
}
