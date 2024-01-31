/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert_staline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:34:04 by gcros             #+#    #+#             */
/*   Updated: 2024/01/31 17:44:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"
#include "ft_utils.h"

static int	stalin(t_sort *sort);

int	ft_quad_insert_staline(t_sort *sort)
{
	t_cost	best_cost;

	if (stalin(sort) == -1)
		return (-1);
	if (ft_run_op(sort, PA))
		if (ft_add_operator(sort->instruction, PA) == -1)
			return (-1);
	while (sort->stack_b->size > 0)
	{
		best_cost = get_best_move(sort);
		if (ft_goto_a(sort, best_cost.index_a) == -1
			|| ft_goto_b(sort, best_cost.index_b) == -1)
			return (-1);
		if (ft_run_op(sort, PA))
			if (ft_add_operator(sort->instruction, PA) == -1)
				return (-1);
	}
	if (ft_goto_a(sort, ft_find_value(sort->stack_a, 0)) == -1)
		return (-1);
	return (1);
}

static int	stalin(t_sort *sort)
{
	long	big_val;

	big_val = ft_find_value(sort->stack_a, sort->stack_a->size - 1);
	if (ft_goto_a(sort, big_val + 1) == -1)
		return (-1);
	while (sort->stack_a->size >= 2 && sort->stack_a->data[0] != big_val)
	{
		if (sort->stack_a->data[0] > sort->stack_a->data[1])
		{
			if (ft_run_op(sort, PB))
				if (ft_add_operator(sort->instruction, PB) == -1)
					return (-1);
		}
		else
			if (ft_run_op(sort, RA))
				if (ft_add_operator(sort->instruction, RA) == -1)
					return (-1);
	}
	return (1);
}
