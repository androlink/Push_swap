/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_insert_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 03:42:45 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:11:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_utils.h"
#include "ft_sort.h"

int	ft_double_insert_sort(t_sort *ps)
{
	size_t	n;
	size_t	tmp_n;

	if (ft_run_op(ps, PB))
		if (ft_add_operator(ps->instruction, PB) == -1)
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
			if (ft_add_operator(ps->instruction, PB) == -1)
				return (-1);
		if (*(int *)ps->stack_b->data[0] < *(int *)ps->stack_b->data[1])
			if (ft_run_op(ps, RB))
				if (ft_add_operator(ps->instruction, RB) == -1)
					return (-1);
	}
	if (ft_dumb_b(ps) == -1)
		return (-1);
	return (1);
}
