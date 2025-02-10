/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:34 by gcros             #+#    #+#             */
/*   Updated: 2025/02/10 14:58:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_operation.h"
#include <stdio.h>

int	ft_is_sort(t_vector *array)
{
	size_t	i;
	int		tmp1;
	int		tmp2;

	i = 0;
	while (i < array->size - 1)
	{
		ft_vec_get(array, i, &tmp1);
		ft_vec_get(array, i + 1, &tmp2);
		if (tmp1 > tmp2)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_op_str(t_operator op)
{
	static char	*op_list[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra",
		"rrb", "__none__", "ss", "rr", "rrr"};

	return (op_list[op]);
}

int	ft_add_operator(t_vector *instruction, t_operator op)
{
	if (instruction->capacity == instruction->size)
		if (ft_vec_resize(instruction, (instruction->capacity | 2) * 10) == 0)
			return (-1);
	ft_vec_append(instruction, &op);
	return (1);
}
