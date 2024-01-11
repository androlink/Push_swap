/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:42:45 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 10:17:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "arr.h"
#include "ft_utils.h"
#include "put.h"
#include <stdio.h>
#include "ft_printf.h"

static size_t	find_next_value(t_array *arr, int ref_min, int ref_max);
static void go_to(t_push_swap *ps, size_t pos);

int	ft_new_sort(t_push_swap *ps)
{
	size_t	n;
	
	if (ft_run_op(ps, PB))
			ft_add_operator(ps, PB);
	while (ps->stack_a->size)
	{
	//ft_putstr_fd("a : ", 2);ft_put_stack(ps->stack_a);
	//ft_putstr_fd("b : ", 2);ft_put_stack(ps->stack_b);
	//ft_putstr_fd("s : ", 2);ft_put_op(ps->instruction);
		n = find_next_value(ps->stack_a,
			*(int *)ps->stack_b->data[ps->stack_b->size - 1] - 1,
			*(int *)ps->stack_b->data[0] + 1);
		go_to(ps, n);
		if (ft_run_op(ps, PB))
			ft_add_operator(ps, PB);
		if (*(int *)ps->stack_b->data[0] < *(int *)ps->stack_b->data[1])
			if (ft_run_op(ps, RB))
				ft_add_operator(ps, RB);
	}
	
	ft_dumb_b(ps);
	return (1);
}

static ssize_t	find_next_low(t_array *arr, int ref_min)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (*(int *)arr->data[i] == ref_min)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	find_next_up(t_array *arr, int ref_max)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (*(int *)arr->data[i] == ref_max)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	find_next_value(t_array *arr, int ref_min, int ref_max)
{
	ssize_t	i_min;
	ssize_t	i_max;
	size_t s_min;
	size_t s_max;

	i_min = find_next_low(arr, ref_min);
	i_max = find_next_up(arr, ref_max);
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

static void go_to(t_push_swap *ps, size_t pos)
{
	t_operator op;
	
	op = RA;
	if (pos > ps->stack_a->size/2)
	{
		op = RRA;
		pos = ps->stack_a->size - pos;
	}
	while (pos-- > 0)
	{
		if (ft_run_op(ps, op))
			ft_add_operator(ps, op);
	}
}
