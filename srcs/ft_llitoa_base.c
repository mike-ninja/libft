/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:09:23 by mbarutel          #+#    #+#             */
/*   Updated: 2022/05/16 11:36:25 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_char_val:
**	: Fetches the character value from the int
*/
static char	ft_char_val(unsigned long long val)
{
	char	ret;

	if (val >= 10)
		ret = (val - 10) + 'a';
	else
		ret = val + '0';
	return (ret);
}

/*
**	ft_deci_len:
**	: Calculates the amount of digits based on the base. Kind of like ft_strlen
*/
static int	ft_deci_len(unsigned long long val, int base)
{
	int	len;

	len = 0;
	if (val == 0)
		len++;
	if (val < 0 && base == 10)
		len++;
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
char	*ft_llitoa_base(long long value, int base)
{
	int					len;
	unsigned long long	tmp;
	char				*ret;

	len = 0;
	if (value < 0 && base == 10)
		tmp = value * -1;
	else
		tmp = (unsigned long long)value;
	len += ft_deci_len(tmp, base);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (tmp)
	{
		ret[--len] = ft_char_val(tmp % base);
		tmp /= base;
	}
	if (value == 0)
		ret[--len] = '0';
	if (value < 0 && base == 10)
		ret[--len] = '-';
	return (ret);
}
