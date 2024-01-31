/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:10:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/31 18:46:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_operation.h"
#include "ft_utils.h"

int	ft_check_op(t_sort *sort, t_operator op);

int	ft_apply_op(t_sort *sort)
{
	size_t	i;

	i = 0;
	while (i < sort->instruction->size)
	{
		if (ft_check_op(sort, *(t_operator *)sort->instruction->data[i]) == -1)
			return (-1);
		i++;
	}
	return (sort->stack_b->size == 0 && ft_is_sort(sort->stack_a));
}

int	ft_check_op(t_sort *sort, t_operator op)
{
	if (op == NONE)
		return (-1);
	if (op < NONE)
		return (ft_run_op(sort, op));
	if (op == SS)
		if (ft_run_op(sort, SA) == -1 || ft_run_op(sort, SB) == -1)
			return (-1);
	if (op == RR)
		if (ft_run_op(sort, RA) == -1 || ft_run_op(sort, RB) == -1)
			return (-1);
	if (op == RRR)
		if (ft_run_op(sort, RRA) == -1 || ft_run_op(sort, RRB) == -1)
			return (-1);
	return (1);
}
