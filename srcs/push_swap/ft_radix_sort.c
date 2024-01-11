/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:15:27 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 03:42:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "ft_utils.h"

int ft_radix_sort(t_push_swap *ps)
{
	int	flag;
	size_t	j;

	flag = 1;
	while (flag > 0)
	{
		j = ps->stack_a->size;
		while (j > 0 && !ft_is_sort(ps->stack_a))
		{
			if (*((int *)ps->stack_a->data[0]) & flag)
			{
				if (ft_run_op(ps, RA))
					ft_add_operator(ps, RA);
			}
			else
			{
				if (ft_run_op(ps, PB))
					ft_add_operator(ps, PB);
			}
			j--;
		}
		ft_dumb_b(ps);
		flag *= 2;
	}
	return (1);
}
