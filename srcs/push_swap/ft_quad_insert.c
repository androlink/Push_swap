/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:34:04 by gcros             #+#    #+#             */
/*   Updated: 2025/02/13 16:39:00 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"
#include "ft_utils.h"

#include "push_swap.h"

int	ft_quad_insert(t_sort *sort)
{

	if (ft_dump_a(sort) == -1)
		return (-1);
	if (ft_run_op(sort, PA) == 1)
		if (ft_add_operator(sort->instruction, PA) == -1)
			return (-1);
	return (turc_side_sort(sort));
}

int	turc_side_sort(t_sort *sort)
{
	t_cost	best_cost;

	while (sort->stack_b->size > 0)
	{
		best_cost = get_best_move(sort);
		if (ft_goto_a(sort, best_cost.index_a) == -1
			|| ft_goto_b(sort, best_cost.index_b) == -1)
			return (-1);
		if (ft_run_op(sort, PA) == 1)
			if (ft_add_operator(sort->instruction, PA) == -1)
				return (-1);
	}
	if (ft_goto_a(sort, ft_find_value(sort->stack_a, 0)) == -1)
		return (-1);
	return (1);
}
