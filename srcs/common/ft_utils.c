/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:34 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 04:38:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arr.h"
#include "put.h"
#include "ft_printf.h"
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

void	ft_put_stack(t_array *array)
{
	size_t	i;

	i = 0;
	while (i < array->size)
	{
		ft_putnbr_fd((*((int *)array->data[i])), 2);
		write(2, ", ", 2);
		i++;
	}
	write(2, "\n", 1);
}

int	ft_is_sort(t_array *array)
{
	size_t	i;
	
	i = 0;
	while (i < array->size - 1)
	{
		//ft_printf("%d ?? %d\n", *(int *)array->data[i], *(int *)array->data[i + 1]);
		if (*(int *)array->data[i] > *(int *)array->data[i + 1])
			return (0);
		i++;
	}	
	return (1);	
}

char	*ft_get_op_str(t_operator op)
{
	static char *op_list[] = {"sa", "sb", "pa", "pb", "ra", "rb", "rra", "rrb", "__none__", "ss", "rr", "rrr"};

	return (op_list[op]);
}

void	ft_put_op(t_array *array)
{
	size_t	i;

	i = 0;
	while (i < array->size)
	{
		ft_putstr_fd(ft_get_op_str(*(t_operator *)array->data[i]), 1);
		write(1, "\n", 1);
		i++;
	}
	//write(1, "\n", 1);
}
