/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:50:37 by mbarutel          #+#    #+#             */
/*   Updated: 2022/11/18 16:56:18 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec.h"

/**
 * It frees the memory allocated to the vector.
 * 
 * @param src The vector to free.
 * 
 * @return A pointer to the new vector.
 */
void	ft_vec_free(t_vec *src)
{
	if (!src || src->alloc_size == 0)
		return ;
	ft_memdel((void *)&src->memory);
	src->elem_size = 0;
	src->alloc_size = 0;
	src->len = 0;
}