/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stalinsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:17:40 by gcros             #+#    #+#             */
/*   Updated: 2025/02/13 16:40:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"
#include "push_swap.h"

int	ps_stalin(t_sort *sort);

int	ps_stalinsort(t_sort *sort)
{
	if (ps_stalin(sort) == -1)
		return (-1);
	if (ft_run_op(sort, PA) == 1)
		if (ft_add_operator(sort->instruction, PA) == -1)
			return (-1);
	return (turc_side_sort(sort));
}

int	ps_stalin(t_sort *sort)
{
	size_t			i;
	const t_vector	*s_a = sort->stack_a;

	i = 0;
	while (i < s_a->size - 1)
	{
		if (((int *)s_a->data)[i] > ((int *)s_a->data)[i + 1]
			&& ((unsigned int *)s_a->data)[i] != s_a->size - 1)
		{
			if (ft_goto_a(sort, i + 1) == -1)
				return (-1);
			if (ft_run_op(sort, PB) == 1)
				if (ft_add_operator(sort->instruction, PB) == -1)
					return (-1);
			if (ft_run_op(sort, RRA) == 1)
				if (ft_add_operator(sort->instruction, RRA) == -1)
					return (-1);
			i = 0;
		}
		else
			i++;
	}
	return (1);
}
