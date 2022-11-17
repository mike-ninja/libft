/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:09:20 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:35:25 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*ptr;

	if (s && f)
	{
		i = 0;
		str = (char *)s;
		ptr = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!ptr)
		{
			ft_strdel(&ptr);
			return (NULL);
		}
		while (str[i] != '\0')
		{
			ptr[i] = f(str[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
