/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:34 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:09:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_operation.h"

int	ft_dumb_b(t_sort *ps)
{
	while (ps->stack_b->size > 0)
	{
		if (ft_run_op(ps, PA))
			if (ft_add_operator(ps->instruction, PA) == -1)
				return (-1);
	}
	return (1);
}

int	ft_dumb_a(t_sort *ps)
{
	while (ps->stack_a->size != 0)
	{
		if (ft_run_op(ps, PB))
			if (ft_add_operator(ps->instruction, PB) == -1)
				return (-1);
	}
	return (1);
}

int	ft_is_sort(t_array *array)
{
	size_t	i;

	i = 0;
	while (i < array->size - 1)
	{
		if (*(int *)array->data[i] > *(int *)array->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_get_op_str(t_operator op)
{
	static char	*op_list[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra",
		"rrb", "__none__", "ss", "rr", "rrr"};

	return (op_list[op]);
}
