/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:15:27 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 16:56:53 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_radix_sort(t_sort *sort)
{
	long	flag;
	size_t	j;

	flag = 1;
	while (flag > 0)
	{
		j = sort->stack_a->size;
		while (j > 0 && !ft_is_sort(sort->stack_a))
		{
			if (*((long *)sort->stack_a->data[0]) & flag)
			{
				if (ft_run_op(sort, RA))
					if (ft_add_operator(sort->instruction, RA) == -1)
						return (-1);
			}
			else
				if (ft_run_op(sort, PB))
					if (ft_add_operator(sort->instruction, PB) == -1)
						return (-1);
			j--;
		}
		ft_dumb_b(sort);
		flag *= 2;
	}
	return (1);
}
