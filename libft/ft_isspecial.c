/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:05:05 by mbarutel          #+#    #+#             */
/*   Updated: 2022/11/17 17:20:47 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * It returns 1 if the character is a special character, and 0 if it isn't
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is a special character, otherwise it returns 0.
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
