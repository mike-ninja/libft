/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:41:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/09/04 16:06:45 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_tail(char *head, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(head, str);
	free(tmp);
	return (str);
}
