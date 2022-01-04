/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:30:51 by mbarutel          #+#    #+#             */
/*   Updated: 2022/01/03 16:36:49 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;

	if (ptr && size)
	{
		tmp = ft_memalloc(size);
		ft_strcpy(tmp, ptr);
		ft_strdel(((void *)&ptr));
		return (tmp);
	}
	return (NULL);
}
