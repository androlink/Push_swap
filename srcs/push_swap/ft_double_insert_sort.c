/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_insert_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:42:45 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 17:03:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_utils.h"
#include "ft_sort.h"

int	ft_double_insert_sort(t_sort *sort)
{
	size_t	n;
	size_t	tmp_n;

	if (ft_run_op(sort, PB))
		if (ft_add_operator(sort->instruction, PB) == -1)
			return (-1);
	while (sort->stack_a->size)
	{
		n = ft_find_value(sort->stack_a,
				*(long *)sort->stack_b->data[sort->stack_b->size - 1] - 1);
		tmp_n = ft_find_value(sort->stack_a,
				*(long *)sort->stack_b->data[0] + 1);
		if (ft_get_dist(sort->stack_a, n) > ft_get_dist(sort->stack_a, tmp_n))
			n = tmp_n;
		ft_goto_a(sort, n);
		if (ft_run_op(sort, PB))
			if (ft_add_operator(sort->instruction, PB) == -1)
				return (-1);
		if (*(long *)sort->stack_b->data[0] < *(long *)sort->stack_b->data[1])
			if (ft_run_op(sort, RB))
				if (ft_add_operator(sort->instruction, RB) == -1)
					return (-1);
	}
	return (ft_dumb_b(sort));
}
