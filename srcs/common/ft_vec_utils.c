/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:07:21 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:31:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "mem.h"

int	ft_vec_push(t_vector *vector, void *elem)
{
	if (vector->size == vector->capacity)
		return (0);
	return (ft_vec_append(vector, elem));
}

int	ft_vec_pop(t_vector *vector, void *out)
{
	if (vector->size == 0)
		return (0);
	ft_vec_get(vector, vector->size - 1, out);
	vector->size--;
	return (1);
}

int	ft_vec_unshift(t_vector *vector, void *elem)
{
	if (vector->size == vector->capacity)
		return (0);
	if (ft_vec_append(vector, elem) == 0)
		return (0);
	ft_memmove(((char *)vector->data) + vector->elem_size,
		vector->data,
		vector->elem_size * (vector->size - 1));
	ft_memmove(vector->data, elem, vector->elem_size);
	return (1);
}

int	ft_vec_shift(t_vector *vector, void *out)
{
	if (vector->size == 0)
		return (0);
	ft_memmove(out, vector->data, vector->elem_size);
	ft_memmove(vector->data,
		((char *)vector->data) + vector->elem_size,
		vector->elem_size * (vector->size - 1));
	vector->size--;
	return (1);
}
