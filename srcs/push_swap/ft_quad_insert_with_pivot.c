/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert_with_pivot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:34:04 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:13:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_quad_insert_with_pivot.h"

static int		push_value_pivot(t_sort *ps, int pivot);
static t_cost	get_cost(t_sort *ps, int value);
static t_cost	get_best_move(t_sort *ps);
static size_t	get_pot_index(t_array *array, int value);

int	ft_quad_insert_with_pivot(t_sort *ps)
{
	t_cost	best_cost;
	int		pivot;

	pivot = ps->stack_a->size;
	if (push_value_pivot(ps, (pivot * 1) / 2) == -1)
		return (-1);
	if (push_value_pivot(ps, ((pivot * 0) / 2) - 1) == -1)
		return (-1);
	if (ft_run_op(ps, PA))
		if (ft_add_operator(ps->instruction, PA) == -1)
			return (-1);
	while (ps->stack_b->size > 0)
	{
		best_cost = get_best_move(ps);
		if (ft_goto_a(ps, best_cost.index_a) == -1
			|| ft_goto_b(ps, best_cost.index_b) == -1)
			return (-1);
		if (ft_run_op(ps, PA))
			if (ft_add_operator(ps->instruction, PA) == -1)
				return (-1);
	}
	if (ft_goto_a(ps, ft_find_value(ps->stack_a, 0)) == -1)
		return (-1);
	return (1);
}

static t_cost	get_best_move(t_sort *ps)
{
	size_t	i;
	t_cost	best_cost;
	t_cost	cost_tmp;

	i = 0;
	best_cost.cost = __SIZE_MAX__;
	while (i < ps->stack_b->size)
	{
		cost_tmp = get_cost(ps, i);
		if (cost_tmp.cost < best_cost.cost)
			best_cost = cost_tmp;
		++i;
	}
	return (best_cost);
}

static t_cost	get_cost(t_sort *ps, int index)
{
	t_cost	dist;

	dist.index_b = index;
	dist.index_a = get_pot_index(ps->stack_a, *(int *)ps->stack_b->data[index]);
	dist.cost = ft_get_dist(ps->stack_a, dist.index_a);
	dist.cost += ft_get_dist(ps->stack_b, dist.index_b);
	return (dist);
}

static size_t	get_pot_index(t_array *array, int value)
{
	size_t	i;
	int		n_val;

	i = 0;
	n_val = __INT_MAX__;
	while (i < array->size)
	{
		if (*(int *)array->data[i] > value && *(int *)array->data[i] < n_val)
			n_val = *(int *)array->data[i];
		i++;
	}
	if (n_val == __INT_MAX__)
	{
		n_val = *(int *)array->data[0];
		i = 0;
		while (++i < array->size)
			if (*(int *)array->data[i] < n_val)
				n_val = *(int *)array->data[i];
	}
	return (ft_find_value(array, n_val));
}

static int	push_value_pivot(t_sort *ps, int pivot)
{
	size_t	i;

	i = ps->stack_a->size;
	while (i > 0)
	{
		if (*(int *)ps->stack_a->data[0] < pivot)
		{
			if (ft_run_op(ps, RA))
				if (ft_add_operator(ps->instruction, RA) == -1)
					return (-1);
		}
		else
			if (ft_run_op(ps, PB))
				if (ft_add_operator(ps->instruction, PB) == -1)
					return (-1);
		i--;
	}
	return (1);
}
