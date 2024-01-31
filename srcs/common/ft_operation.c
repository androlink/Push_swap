/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:46:37 by gcros             #+#    #+#             */
/*   Updated: 2024/01/31 04:40:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"

static int	ft_op_rotate(t_array *arr);
static int	ft_op_revrot(t_array *arr);
static int	ft_op_swap(t_array *arr);
static int	ft_op_push(t_array *arr1, t_array *arr2);

int	ft_run_op(t_sort *ptr, t_operator op)
{
	if (op == SA)
		return (ft_op_swap(ptr->stack_a));
	else if (op == SB)
		return (ft_op_swap(ptr->stack_b));
	else if (op == PA)
		return (ft_op_push(ptr->stack_a, ptr->stack_b));
	else if (op == PB)
		return (ft_op_push(ptr->stack_b, ptr->stack_a));
	else if (op == RA)
		return (ft_op_rotate(ptr->stack_a));
	else if (op == RB)
		return (ft_op_rotate(ptr->stack_b));
	else if (op == RRA)
		return (ft_op_revrot(ptr->stack_a));
	else if (op == RRB)
		return (ft_op_revrot(ptr->stack_b));
	return (-1);
}

static int	ft_op_rotate(t_array *arr)
{
	int	*tmp;

	if (arr->size < 2)
		return (0);
	tmp = ft_arr_shift(arr);
	ft_arr_push(arr, tmp);
	return (1);
}

static int	ft_op_revrot(t_array *arr)
{
	int	*tmp;

	if (arr->size <= 1)
		return (0);
	tmp = ft_arr_pop(arr);
	ft_arr_unshift(arr, tmp);
	return (1);
}

static int	ft_op_swap(t_array *arr)
{
	int	*p;

	if (arr->size <= 1)
		return (0);
	p = arr->data[0];
	arr->data[0] = arr->data[1];
	arr->data[1] = p;
	return (1);
}

static int	ft_op_push(t_array *arr1, t_array *arr2)
{
	int	*tmp;

	if (arr2->size == 0)
		return (0);
	tmp = ft_arr_shift(arr2);
	ft_arr_unshift(arr1, tmp);
	return (1);
}
