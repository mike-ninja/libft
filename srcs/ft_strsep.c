/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:51:32 by mbarutel          #+#    #+#             */
/*   Updated: 2022/07/21 13:52:13 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/*
**	ft_strsep:
**	  The strsep() function locates, in the string referenced by *stringp, the 
**   first occurrence of any character in the string delim (or the
**  terminating ‘\0’ character) and replaces it with a ‘\0’.  The location of 
**  the next character after the delimiter character (or NULL, if the
**  end of the string was reached) is stored in *stringp.  The original value of 
**  *stringp is returned.
**  string pointed to by s.
*/

static int	ft_charcmp(const char c, const char *delim)
{
	while (delim[0] != '\0')
	{
		if (c == delim[0])
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strsep(char **stringp, const char *delim)
{
	int		i;
	char	*ptr;

	if (stringp)
	{
		i = 0;
		ptr = *stringp;
		while (stringp[0][i] != '\0' && ft_charcmp(stringp[0][i], delim) == 0)
			i++;
		if (stringp[0][i] == '\0')
			*stringp = NULL;
		else
		{
			stringp[0][i] = '\0';
			*stringp = &stringp[0][i + 1];
		}
		return (ptr);
	}
	return (NULL);
}
