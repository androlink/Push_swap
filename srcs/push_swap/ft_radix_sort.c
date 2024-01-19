/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:15:27 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:14:27 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_radix_sort(t_sort *ps)
{
	int		flag;
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
					if (ft_add_operator(ps->instruction, RA) == -1)
						return (-1);
			}
			else
				if (ft_run_op(ps, PB))
					if (ft_add_operator(ps->instruction, PB) == -1)
						return (-1);
			j--;
		}
		ft_dumb_b(ps);
		flag *= 2;
	}
	return (1);
}
