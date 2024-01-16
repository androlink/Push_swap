/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:07:12 by gcros             #+#    #+#             */
/*   Updated: 2024/01/12 22:52:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "ft_printf.h"
#include "ft_utils.h"

t_operator	ft_get_op_rev(t_operator op)
{
	static t_operator op_list[] = {SA, SB, PB, PA, RRA, RRB, RA, RB, NONE, SS, RRR, RR};

	//ft_printf("=== %s >> %s ===\n", ft_get_op_str(op), ft_get_op_str(op_list[op]));
	
	return (op_list[op]);
}

t_operator	*ft_get_op(t_operator op)
{
	static t_operator op_list[] = {SA, SB, PA, PB, RA, RB, RRA, RRB, NONE, SS, RR, RRR};
	
	return (&op_list[op]);
}

size_t	ft_get_min(t_array *array)
{
	size_t	i;
	size_t	bi;
	int	value;

	value = __INT_MAX__;
	bi = 0;
	i = 0;
	while (i < array->size)
	{
		if (*(int *)array->data[i] < value)
		{
			value = *(int *)array->data[i];
			bi = i;
		}
		i++;
	}
	return (bi);
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
t_operator	ft_get_last_op(t_array *array)
{
	return (*(t_operator *)array->data[array->size - 1]);
}
