/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:15:27 by gcros             #+#    #+#             */
/*   Updated: 2025/02/07 17:05:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_vector *stack, const char *name)
{
	printf("%s: ", name);
	for (size_t i = 0; i < stack->size; i++)
			printf("%ld, ", ((long *)stack->data)[i]);
	printf("\n");
}

int	ft_radix_sort(t_sort *sort)
{
	long	flag;
	size_t	j;

	flag = 1;
	while (flag > 0 && !ft_is_sort(sort->stack_a))
	{
		j = sort->stack_a->size;
		while (j > 0)
		{
			if (((long *)sort->stack_a->data)[0] & flag)
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
		// print_stack(sort->stack_a, "a");
		// print_stack(sort->stack_b, "b");
		}
		ft_dump_b(sort);
		flag *= 2;
		// printf("%d\n", ft_is_sort(sort->stack_a));
	}
	return (1);
}
