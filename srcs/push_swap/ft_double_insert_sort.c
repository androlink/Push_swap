/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_insert_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:42:45 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 04:42:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "arr.h"
#include "ft_utils.h"
#include "ft_sort.h"
#include "put.h"
#include <stdio.h>
#include "ft_printf.h"

int	ft_double_insert_sort(t_sort *ps)
{
	size_t	n;
	size_t	tmp_n;
	if (ft_run_op(ps, PB))
			if(ft_add_operator(ps->instruction, PB) == -1)
				return (-1);
	while (ps->stack_a->size)
	{
		n = ft_find_value(ps->stack_a,
			*(int *)ps->stack_b->data[ps->stack_b->size - 1] - 1);
		tmp_n = ft_find_value(ps->stack_a, *(int *)ps->stack_b->data[0] + 1);
		if (ft_get_dist(ps->stack_a, n) > ft_get_dist(ps->stack_a, tmp_n))
			n = tmp_n;
		ft_goto_a(ps, n);
		if (ft_run_op(ps, PB))
			if(ft_add_operator(ps->instruction, PB) == -1)
				return (-1);
		if (*(int *)ps->stack_b->data[0] < *(int *)ps->stack_b->data[1])
			if (ft_run_op(ps, RB))
				if(ft_add_operator(ps->instruction, RB) == -1)
					return (-1);
	}
	if (ft_dumb_b(ps) == -1)
		return (-1);
	return (1);
}

/*
static size_t	find_next_value(t_array *arr, int ref_min, int ref_max)
{
	ssize_t	i_min;
	ssize_t	i_max;
	size_t s_min;
	size_t s_max;

	i_min = find_value(arr, ref_min);
	i_max = find_value(arr, ref_max);
	//dprintf(2, "find next %d : %d\n", ref_min, ref_max);
	//dprintf(2, "found at %ld : %ld\n", i_min, i_max);

	if (i_min == -1)
		return (i_max);
	if (i_max == -1)
		return (i_min);
	s_min = i_min;
	s_max = i_max;
	if (s_max < s_min && s_max < arr->size/2)
		return (s_max);
	if (s_max > s_min && s_max < arr->size/2)
		return (s_min);
	if (s_max > s_min && s_max > arr->size/2)
		return (s_max);
	return (s_min);
}
*/
