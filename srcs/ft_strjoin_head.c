/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:40:55 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/09 14:43:07 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*strjoin_head(char *str, char *tail)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, tail);
	free(tmp);
	return (str);
}
