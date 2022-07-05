/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:44:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/05 12:21:49 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"
#include <stdio.h>

static char	*joiner(char *sign, char *str, long *base)
{
	char	*tmp;
	char	*base_str;

	tmp = str;
	base_str = ft_ltoa_base(base[0], 10);
	str = ft_strjoin(base_str, str);
	free(tmp);
	free(base_str);
	if (sign)
	{
		tmp = str;
		str = ft_strjoin(sign, str);
		free(tmp);
		free(sign);
	}
	return (str);
}

static void	banker_round(double nbr, char *dl_str, long *base, size_t precision)
{
	int	len;

	len = ft_strlen(dl_str) - 1;
	if (((long)(nbr * 10)) % 10 >= 5)
	{
		if (dl_str[len] == '9')
		{
			while (len >= 0)
			{
				if (dl_str[len] == '9')
					dl_str[len--] = '0';
				else
				{
					if (dl_str[len] == '.')
					{
						// printf("This happens\n");
						// if ((base[0] % 2) != 0)
							base[0]++;
					}
					else
					{
						if (((dl_str[len] - '0') % 2) != 0)
							dl_str[len]++;
					}
					break;
				}
			}
		}
		else
		{
			// if (((dl_str[len] - '0') % 2) != 0)
				dl_str[len]++;
		}
			
	}
	if (precision == 0 && (((long)(nbr * 10)) % 10 >= 5))
		if ((base[0] % 2) != 0)
			base[0]++;
}

static char	*remainder(double nbr, size_t precision, long *base_l)
{
	char	*ret;
	char	*tmp;
	long	base;
	int		index;

	tmp = NULL;
	if (precision == 0)
	{
		if (((long)(nbr * 10)) % 10 >= 5)
			if ((base_l[0] % 2) != 0)
				base_l[0]++;
		return (ft_strdup(""));	
	}
		
	ret = (char *)malloc(precision + 1);
	if (!ret)
		return (NULL);
	index = 0;
	ret[precision] = '\0';
	while (precision--)
	{
		nbr *= 10;
		base = ((long)nbr);
		ret[index++] = (base % 10) + '0';
		nbr -= (long double)base;
	}
	tmp = ret;
	ret = ft_strjoin(".", ret);
	free(tmp);
	banker_round(nbr, ret, base_l, precision);
	return (ret);
}

char	*ft_ftoa(double nbr, size_t precision)
{
	char	*ret;
	char	*sign;
	long	*base;

	ret = NULL;
	sign = NULL;
	base = (long *)malloc(sizeof(long));
	if (!base)
		return (NULL);
	if (1 / nbr < 0)
	{
		sign = ft_strdup("-");
		nbr *= -1;
	}
	*base = (long)nbr;
	nbr -= (double)base[0];
	ret = remainder(nbr, precision, base);
	ret = joiner(sign, ret, base);
	free(base);
	return (ret);
}
