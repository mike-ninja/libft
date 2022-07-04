/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:44:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/04 13:22:42 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

static void	banker_round(double nbr, char *dl_str)
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
				else if (dl_str[len] == '.')
					len--;
				else
				{
					dl_str[len]++;
					break ;
				}
			}
		}
		else
			dl_str[len]++;
	}
}

static char	*remainder(double nbr, size_t precision)
{
	char	*ret;
	char	*tmp;
	long	base;
	int		index;

	tmp = NULL;
	ret = (char *)malloc(precision + 1);
	if (!ret || precision == 0)
		return (NULL);
	index = 0;
	ret[precision] = '\0';
	while (precision--)
	{
		nbr *= 10;
		base = ((long)nbr) % 10;
		ret[index++] = base + '0';
	}
	tmp = ret;
	ret = ft_strjoin(".", ret);
	free(tmp);
	// free(nb);
	banker_round(nbr, ret);
	return (ret);
}

static char	*joiner(char *str, long base, double nbr)
{
	char	*tmp;

	if (!str)
	{
		if (((long)(nbr * 10)) % 10 >= 5 && base % 2 != 0)
			base++;
		return(ft_ltoa_base(base, 10));	
	}
	else
	{
		tmp = str;
		// if (((long)(nbr * 10)) % 10 == 9)
		// 	base++;
		str = ft_strjoin(ft_ltoa_base(base, 10), str);
		free(tmp);
	}
	// if (precision)
	// {
	// 	tmp = str;
	// 	str = ft_strjoin(tmp, ".");
	// 	free(tmp);
	// }
	return (str);
}

char	*ft_ftoa(double nbr, size_t precision)
{
	char	*ret;
	long	base;

	ret = NULL;
	// if (1 / nbr < 0)
	// {
	// 	ret = ft_strdup("-");
	// 	nbr *= -1;
	// }
	base = (long)nbr;
	nbr -= (double)base;
	ret = remainder(nbr, precision);
	ret = joiner(ret, base, nbr);
	return (ret);
}
