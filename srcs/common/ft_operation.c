/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:46:37 by gcros             #+#    #+#             */
/*   Updated: 2025/02/07 22:23:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "vector.h"

static int	ft_op_rotate(t_vector *arr);
static int	ft_op_revrot(t_vector *arr);
static int	ft_op_swap(t_vector *arr);
static int	ft_op_push(t_vector *arr1, t_vector *arr2);

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

static int	ft_op_rotate(t_vector *arr)
{
	long	tmp;

	if (arr->size < 2)
		return (0);
	ft_vec_shift(arr, &tmp);
	ft_vec_push(arr, &tmp);
	return (1);
}

static int	ft_op_revrot(t_vector *arr)
{
	long	tmp;

	if (arr->size <= 1)
		return (0);
	ft_vec_pop(arr, &tmp);
	ft_vec_unshift(arr, &tmp);
	return (1);
}

static int	ft_op_swap(t_vector *arr)
{
	long	p;

	if (arr->size <= 1)
		return (0);
	p = ((long *)arr->data)[0];
	((long *)arr->data)[0] = ((long *)arr->data)[1];
	((long *)arr->data)[1] = p;
	return (1);
}

static int	ft_op_push(t_vector *arr1, t_vector *arr2)
{
	long	tmp;

	if (arr2->size == 0)
		return (0);
	ft_vec_shift(arr2, &tmp);
	ft_vec_unshift(arr1, &tmp);
	return (1);
}
