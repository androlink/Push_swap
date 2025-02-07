/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert_with_pivot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:34:04 by gcros             #+#    #+#             */
/*   Updated: 2025/02/07 21:56:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"
#include "push_swap.h"

static int		push_value_pivot(t_sort *sort, long pivot);
static size_t	get_pot_index(t_vector *array, long value);

int	ft_quad_insert_with_pivot(t_sort *sort)
{
	t_cost	best_cost;
	long	pivot;

	pivot = sort->stack_a->size;
	if (push_value_pivot(sort, (pivot * 1) / 2) == -1)
		return (-1);
	if (push_value_pivot(sort, ((pivot * 0) / 2) - 1) == -1)
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
			((long *)sort->stack_b->data)[index]);
	dist.cost = ft_get_dist(sort->stack_a, dist.index_a);
	dist.cost += ft_get_dist(sort->stack_b, dist.index_b);
	return (dist);
}

static size_t	get_pot_index(t_vector *array, long value)
{
	size_t	i;
	long	n_val;

	i = 0;
	n_val = __LONG_MAX__;
	while (i < array->size)
	{
		if (((long *)array->data)[i] > value
			&& ((long *)array->data)[i] < n_val)
			n_val = ((long *)array->data)[i];
		i++;
	}
	if (n_val == __LONG_MAX__)
	{
		n_val = ((long *)array->data)[0];
		i = 0;
		while (++i < array->size)
			if (((long *)array->data)[i] < n_val)
				n_val = ((long *)array->data)[i];
	}
	return (ft_find_value(array, n_val));
}

static int	push_value_pivot(t_sort *sort, long pivot)
{
	size_t	i;

	i = sort->stack_a->size;
	while (i > 0)
	{
		if (((long *)sort->stack_a->data)[0] < pivot)
		{
			if (ft_run_op(sort, RA))
				if (ft_add_operator(sort->instruction, RA) == -1)
					return (-1);
		}
		else
			if (ft_run_op(sort, PB))
				if (ft_add_operator(sort->instruction, PB) == -1)
					return (-1);
		i--;
	}
	return (1);
}
