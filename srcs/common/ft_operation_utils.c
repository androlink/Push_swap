/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:07:12 by gcros             #+#    #+#             */
/*   Updated: 2025/02/10 09:10:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

t_operator	ft_get_op_rev(t_operator op)
{
	static t_operator	ops[] = {
		SA,
		SB,
		PB,
		PA,
		RRA,
		RRB,
		RA,
		RB,
		NONE,
		SS,
		RRR,
		RR
	};

	return (ops[op]);
}

t_operator	*ft_get_op(t_operator op)
{
	static t_operator	ops[] = {
		SA,
		SB,
		PA,
		PB,
		RA,
		RB,
		RRA,
		RRB,
		NONE,
		SS,
		RR,
		RRR
	};

	return (&ops[op]);
}

t_operator	ft_get_merge_op(t_operator op1, t_operator op2)
{
	if ((op1 == SA && op2 == SB) || (op1 == SB && op2 == SA))
		return (SS);
	if ((op1 == RA && op2 == RB) || (op1 == RB && op2 == RA))
		return (RR);
	if ((op1 == RRA && op2 == RRB) || (op1 == RRB && op2 == RRA))
		return (RRR);
	return (NONE);
}

t_operator	ft_get_last_op(t_vector *array)
{
	t_operator	op;

	op = NONE;
	ft_vec_get(array, array->size - 1, &op);
	return (op);
}
