/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_insert_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:42:45 by gcros             #+#    #+#             */
/*   Updated: 2025/02/09 18:40:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_utils.h"
#include "ft_sort.h"
#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_vector *stack, const char *name);
int	ft_double_insert_sort_brain(t_sort *sort);

int	ft_double_insert_sort(t_sort *sort)
{
	if (IGNORE_DOUBLE_INSERT)
		return (-1);
	return (ft_double_insert_sort_brain(sort));
}

int	ft_double_insert_sort_brain(t_sort *sort)
{
	size_t	n;
	size_t	tmp_n;

	if (ft_run_op(sort, PB))
		if (ft_add_operator(sort->instruction, PB) == -1)
			return (-1);
	while (sort->stack_a->size > 0)
	{
		n = ft_find_value(sort->stack_a,
				((long *)sort->stack_b->data)[sort->stack_b->size - 1] - 1);
		tmp_n = ft_find_value(sort->stack_a,
				((long *)sort->stack_b->data)[0] + 1);
		if (ft_get_dist(sort->stack_a, n) > ft_get_dist(sort->stack_a, tmp_n))
			n = tmp_n;
		if (ft_goto_a(sort, n) == -1)
			return (-1);
		if (ft_run_op(sort, PB))
			if (ft_add_operator(sort->instruction, PB) == -1)
				return (-1);
		if (((long *)sort->stack_b->data)[0] < ((long *)sort->stack_b->data)[1])
			if (ft_run_op(sort, RB))
				if (ft_add_operator(sort->instruction, RB) == -1)
					return (-1);
	}
	return (ft_dump_b(sort));
}
