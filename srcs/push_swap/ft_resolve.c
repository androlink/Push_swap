/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:56:58 by gcros             #+#    #+#             */
/*   Updated: 2024/02/01 01:05:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

t_array	*ft_merge_op(t_array *inst)
{
	t_array		*result;
	t_array		*tmp;
	t_operator	op_tmp;

	result = ft_arr_new(inst->size);
	tmp = ft_arr_new(inst->size);
	if (result == NULL || tmp == NULL)
		return (ft_arr_free(&tmp, NULL), ft_arr_free(&result, NULL), NULL);
	while (inst->size > 0)
	{
		ft_arr_push(result, ft_arr_pop(inst));
		while (inst->size > 0 && result->size > 0)
		{
			op_tmp = ft_get_merge_op(ft_get_last_op(result),
					ft_get_last_op(inst));
			if (op_tmp == NONE)
				break ;
			ft_arr_pop(inst);
			ft_arr_pop(result);
			ft_arr_push(tmp, ft_get_op(op_tmp));
		}
		while (tmp->size > 0)
			ft_arr_push(result, ft_arr_pop(tmp));
	}
	return (ft_arr_free(&tmp, NULL), result);
}

t_array	*ft_clean_op(t_array *inst)
{
	t_array	*result;

	result = ft_arr_new(inst->size);
	if (result == NULL)
		return (NULL);
	while (inst->size > 0)
	{
		ft_arr_push(result, ft_arr_pop(inst));
		while (inst->size > 0 && result->size > 0
			&& ft_get_op_rev(*(t_operator *)result->data[result->size - 1])
			== *(t_operator *)inst->data[inst->size - 1])
		{
			ft_arr_pop(inst);
			ft_arr_pop(result);
		}
	}
	return (result);
}

int	ft_dump_b(t_sort *sort)
{
	while (sort->stack_b->size > 0)
	{
		if (ft_run_op(sort, PA))
			if (ft_add_operator(sort->instruction, PA) == -1)
				return (-1);
	}
	return (1);
}

int	ft_dump_a(t_sort *sort)
{
	while (sort->stack_a->size != 0)
	{
		if (ft_run_op(sort, PB))
			if (ft_add_operator(sort->instruction, PB) == -1)
				return (-1);
	}
	return (1);
}
