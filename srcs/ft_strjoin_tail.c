/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:41:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/09 14:43:11 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*strjoin_tail(char *head, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(head, str);
	free(tmp);
	return (str);
}
