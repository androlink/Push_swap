/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 06:09:13 by gcros             #+#    #+#             */
/*   Updated: 2025/02/06 22:07:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static size_t	count_greater(t_vector *values, long val)
{
	size_t	count;
	long	tmp1;
	size_t	i;

	count = 0;
	i = 0;
	while (i < values->size)
	{
		ft_vec_get(values, i, &tmp1);
		if (val > tmp1)
			count++;
		i++;
	}
	return (count);
}

int	normalizer(t_vector **values)
{
	size_t		i;
	long		value;
	long		tmp;
	t_vector	*dup_values;

	dup_values = ft_vec_new((*values)->elem_size);
	if (dup_values == NULL)
		return (-1);
	i = 0;
	while (i < (*values)->size)
	{
		ft_vec_get(*values, i, &tmp);
		value = count_greater(*values, tmp);
		if (ft_vec_append(dup_values, &value) == 0)
		{
			ft_vec_free(&dup_values);
			return (0);
		}
		i++;
	}
	ft_vec_free(values);
	*values = dup_values;
	return (1);
}
