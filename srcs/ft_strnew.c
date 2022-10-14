/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:08 by mbarutel          #+#    #+#             */
/*   Updated: 2021/12/05 12:35:49 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strnew:
**	: Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
**	: Each character of the string is initialized at ’\0’.
**	: If the allocation fails, the function returns NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (ret)
	{
		ft_bzero(ret, size + 1);
		return (ret);
	}
	return (NULL);
}
