/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:09:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 17:00:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

static void	*dup_num(void *value)
{
	long	*nval;

	nval = malloc(sizeof(long));
	if (nval == NULL)
		return (NULL);
	*nval = *(long *)value;
	return (nval);
}

int	normalizer(t_array **array)
{
	size_t	i;
	size_t	j;
	long	value;
	t_array	*norm_arr;

	norm_arr = ft_arr_map(*array, dup_num, free);
	if (norm_arr == NULL)
		return (-1);
	i = 0;
	while (i < norm_arr->size)
	{
		value = 0;
		j = 0;
		while (j < norm_arr->size)
		{
			if (*(long *)norm_arr->data[i] > *(long *)norm_arr->data[j])
				value++;
			j++;
		}
		*(long *)(*array)->data[i] = value;
		i++;
	}
	ft_arr_free(&norm_arr, free);
	return (1);
}
