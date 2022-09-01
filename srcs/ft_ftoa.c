/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:44:54 by mbarutel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/01 10:11:53 by mbarutel         ###   ########.fr       */
=======
/*   Updated: 2022/08/03 13:37:16 by mbarutel         ###   ########.fr       */
>>>>>>> 8e6c8a9e27eba8014972f35f49b24dd474ff8bb0
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

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
	free(base);
	return (str);
}

static void	banker_round(long double nbr, char *dl_str, long *base, size_t len)
{
	if (nbr > 0.5f)
	{
		if (dl_str[len] == '9')
		{
			while (dl_str[len] == '9')
				dl_str[len--] = '0';
			if (dl_str[len] == '.')
				base[0]++;
			else
				dl_str[len]++;
		}
		else
			dl_str[len]++;
	}
	if (nbr == 0.5f && dl_str[len] == '0')
		dl_str[len]++;
}

static char	*precision_zero(double nbr, long *base_l)
{
	if (nbr > 0.5f)
		base_l[0]++;
	else if (nbr == 0.5f)
		if ((base_l[0] % 2) != 0)
			base_l[0]++;
	return (ft_strdup(""));
}

static char	*remain(double nbr, size_t precision, long *base_l)
{
	char		*ret;
	long		base;
	int			index;
	long double	nbr_tmp;

	nbr_tmp = nbr;
	if (precision == 0)
		return (precision_zero(nbr, base_l));
	ret = (char *)malloc(precision + 1);
	if (!ret)
		return (NULL);
	index = 0;
	ret[precision] = '\0';
	while (precision--)
	{
		nbr_tmp *= 10;
		base = ((long)nbr_tmp);
		ret[index++] = (base % 10) + '0';
		nbr_tmp -= base;
	}
	ret = strjoin_tail(".", ret);
	banker_round(nbr_tmp, ret, base_l, (ft_strlen(ret) - 1));
	return (ret);
}

char	*ft_ftoa(double nbr, size_t precision)
{
	char	*ret;
	char	*sign;
	long	*base;

	ret = NULL;
	sign = NULL;
	if (nbr == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (nbr == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (nbr != nbr)
		return (ft_strdup("nan"));
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
	ret = remain(nbr, precision, base);
	ret = joiner(sign, ret, base);
	return (ret);
}
