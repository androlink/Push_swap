/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:11:53 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:29:08 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "put.h"
#include "ft_utils.h"

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

void	print_stack(t_vector *stack, const char *name)
{
	size_t	i;

	ft_putstr_fd((char *)name, 2);
	i = 0;
	while (i < stack->size)
	{
		ft_putnbr_fd(((int *)stack->data)[i], 2);
		ft_putstr_fd(", ", 2);
		i++;
	}
	ft_putendl_fd("", 2);
	ft_putnbr_fd(ft_is_sort(stack), 2);
	ft_putendl_fd("", 2);
}
