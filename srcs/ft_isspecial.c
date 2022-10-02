/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:05:05 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/01 22:56:41 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	ft_isspecial:
	Returns zero if the character tests false and
    returns non-zero if the character tests true.
*/

int	ft_isspecial(int c)
{
	if (c >= 58 && c <= 64)
		return (1);
	if (c >= 91 && c <= 96)
		return (1);
	if (c >= 123 && c <= 126)
		return (1);
	return (0);
}
