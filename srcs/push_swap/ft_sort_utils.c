/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:11:53 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 01:48:01 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_sort.h"
#include "ft_operation.h"
#include "arr.h"
#include "ft_utils.h"
#include "put.h"
#include <stdio.h>
#include "ft_printf.h"

int ft_goto_a(t_sort *ps, size_t pos)
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
			if (ft_add_operator(ps->instruction, op) == -1)
				return (-1);
	}
	return (1);
}

int ft_goto_b(t_sort *ps, size_t pos)
{
	t_operator op;
	
	op = RB;
	if (pos > ps->stack_b->size/2)
	{
		op = RRB;
		pos = ps->stack_b->size - pos;
	}
	while (pos-- > 0)
	{
		if (ft_run_op(ps, op))
			if (ft_add_operator(ps->instruction, op) == -1)
				return (-1);
	}
	return (1);
}

size_t	ft_get_dist(t_array *array, size_t index)
{
	if (index > array->size/2)
		return (array->size - index);
	return (index);
}

ssize_t	ft_find_value(t_array *arr, int value)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
	{
		if (*(int *)arr->data[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
