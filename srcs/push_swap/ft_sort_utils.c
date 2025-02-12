/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:11:53 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 00:10:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

int	ft_goto_a(t_sort *sort, size_t pos)
{
	t_operator	op;

	op = RA;
	if (pos > sort->stack_a->size / 2)
	{
		op = RRA;
		pos = sort->stack_a->size - pos;
	}
	while (pos-- > 0)
	{
		if (ft_run_op(sort, op) == 1)
			if (ft_add_operator(sort->instruction, op) == -1)
				return (-1);
	}
	return (1);
}

int	ft_goto_b(t_sort *sort, size_t pos)
{
	t_operator	op;

	op = RB;
	if (pos > sort->stack_b->size / 2)
	{
		op = RRB;
		pos = sort->stack_b->size - pos;
	}
	while (pos-- > 0)
	{
		if (ft_run_op(sort, op) == 1)
			if (ft_add_operator(sort->instruction, op) == -1)
				return (-1);
	}
	return (1);
}

size_t	ft_get_dist(t_array *array, size_t index)
{
	if (index > array->size / 2)
		return (array->size - index);
	return (index);
}

ssize_t	ft_find_value(t_vector *stack, int value)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (((int *)stack->data)[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
