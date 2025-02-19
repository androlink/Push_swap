/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:10:13 by gcros             #+#    #+#             */
/*   Updated: 2025/02/19 21:00:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_operation.h"
#include "ft_utils.h"
#include "put.h"

static int	ft_check_op(t_sort *sort, t_operator op);
void		print_stack(t_vector *stack, const char *name);

int	ft_apply_op(t_sort *sort)
{
	size_t	i;

	i = 0;
	while (i < sort->instruction->size)
	{
		ft_putendl_fd(ft_get_op_str(((t_operator *)sort->instruction->data)[i]), 2);
		print_stack(sort->stack_a, "a: ");
		print_stack(sort->stack_b, "b: ");
		ft_putendl_fd("-----", 2);
		if (ft_check_op(sort, ((t_operator *)sort->instruction->data)[i]) == -1)
			return (-1);
		i++;
	}
	return (sort->stack_b->size == 0 && ft_is_sort(sort->stack_a));
}

#include "put.h"

static int	ft_check_op(t_sort *sort, t_operator op)
{
	// ft_putendl_fd(ft_get_op_str(op), 2);
	if (op == NONE)
		return (-1);
	if (op < NONE)
		if (ft_run_op(sort, op) == -1)
			return (-1);
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
