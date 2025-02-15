/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert_with_pivot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:34:04 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:25:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"
#include "push_swap.h"
#include "ft_utils.h"
#include "put.h"

static int		push_value_pivot(t_sort *sort, int pivot);
static size_t	get_pot_index(t_vector *array, int value);

int	ft_quad_insert_with_pivot(t_sort *sort)
{
	int		pivot;

	pivot = sort->stack_a->size;
	if (push_value_pivot(sort, (pivot * 1) / 2) == -1)
		return (-1);
	if (push_value_pivot(sort, ((pivot * 0) / 2) - 1) == -1)
		return (-1);
	if (ft_run_op(sort, PA) == 1)
		if (ft_add_operator(sort->instruction, PA) == -1)
			return (-1);
	return (turc_side_sort(sort));
}

t_cost	get_best_move(t_sort *sort)
{
	size_t	i;
	t_cost	best_cost;
	t_cost	cost_tmp;

	i = 0;
	best_cost.cost = __SIZE_MAX__;
	while (i < sort->stack_b->size)
	{
		cost_tmp = get_cost(sort, i);
		if (cost_tmp.cost < best_cost.cost)
			best_cost = cost_tmp;
		++i;
	}
	return (best_cost);
}

t_cost	get_cost(t_sort *sort, size_t index)
{
	t_cost	dist;

	dist.index_b = index;
	dist.index_a = get_pot_index(sort->stack_a,
			((int *)sort->stack_b->data)[index]);
	dist.cost = ft_get_dist(sort->stack_a, dist.index_a);
	dist.cost += ft_get_dist(sort->stack_b, dist.index_b);
	return (dist);
}

static size_t	get_pot_index(t_vector *array, int value)
{
	size_t	i;
	int		n_val;

	i = 0;
	n_val = __INT32_MAX__;
	while (i < array->size)
	{
		if (((int *)array->data)[i] < n_val
			&& ((int *)array->data)[i] > value)
			n_val = ((int *)array->data)[i];
		i++;
	}
	if (n_val == __INT32_MAX__)
	{
		n_val = ((int *)array->data)[0];
		i = 0;
		while (++i < array->size)
			if (((int *)array->data)[i] < n_val)
				n_val = ((int *)array->data)[i];
	}
	return (ft_find_value(array, n_val));
}

static int	push_value_pivot(t_sort *sort, int pivot)
{
	size_t	i;

	i = sort->stack_a->size;
	while (i > 0)
	{
		if (((int *)sort->stack_a->data)[0] < pivot)
		{
			if (ft_run_op(sort, RA) == 1)
				if (ft_add_operator(sort->instruction, RA) == -1)
					return (-1);
		}
		else
			if (ft_run_op(sort, PB) == 1)
				if (ft_add_operator(sort->instruction, PB) == -1)
					return (-1);
		i--;
	}
	return (1);
}
