/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:09:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:06:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"

void	*dup_pint(void *value)
{
	int	*nval;

	nval = malloc(sizeof(int));
	if (nval == NULL)
		return (NULL);
	*nval = *(int *)value;
	return (nval);
}

int	normalizer(t_array **array)
{
	size_t	i;
	size_t	j;
	int		value;
	t_array	*norm_arr;

	norm_arr = ft_arr_map(*array, dup_pint, free);
	if (norm_arr == NULL)
		return (-1);
	i = 0;
	while (i < norm_arr->size)
	{
		value = 0;
		j = 0;
		while (j < norm_arr->size)
		{
			if (*(int *)norm_arr->data[i] > *(int *)norm_arr->data[j])
				value++;
			j++;
		}
		*(int *)(*array)->data[i] = value;
		i++;
	}
	ft_arr_free(&norm_arr, free);
	return (1);
}
