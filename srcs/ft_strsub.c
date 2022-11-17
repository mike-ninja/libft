/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:11:06 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/09 09:33:31 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s && *s)
	{
		ret = (char *)ft_memalloc(sizeof(char) * (len + 1));
		if (ret)
		{
			i = 0;
			while (i < len && start <= ft_strlen(s))
			{
				ret[i] = s[start];
				i++;
				start++;
			}
			ret[i] = '\0';
			return (ret);
		}
	}
	return (NULL);
}
