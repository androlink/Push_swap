/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:56:58 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 01:34:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "ft_printf.h"
#include "ft_utils.h"

int	ft_add_operator(t_array *instruction, t_operator op)
{
	//ft_printf("inst : %d / %d\n", ps->instruction->size, ps->instruction->capacity);
	//ft_printf("stack a : %d / %d\n", ps->stack_a->size, ps->stack_a->capacity);
	//ft_printf("stack b : %d / %d\n", ps->stack_b->size, ps->stack_b->capacity);

	if (instruction->capacity <= instruction->size)
		if (ft_arr_resize(instruction, instruction->capacity + 100) == -1)
			return (-1);
	ft_arr_push(instruction, ft_get_op(op));
	return (1);
}

t_array	*ft_merge_op(t_array *inst)
{
	t_array *result;
	t_array *tmp;
	t_operator op_tmp;

	result = ft_arr_new(inst->size);
	tmp = ft_arr_new(inst->size);
	if (result == NULL || tmp == NULL)
		return (ft_arr_free(&tmp, NULL), ft_arr_free(&result, NULL), NULL);
	while (inst->size > 0)
	{
		ft_arr_push(result, ft_arr_pop(inst));
		while (inst->size > 0 && result->size > 0)
		{
			op_tmp = ft_get_merge_op(ft_get_last_op(result),ft_get_last_op(inst));
			if (op_tmp == NONE)
				break ;
			ft_arr_pop(inst);
			ft_arr_pop(result);
			ft_arr_push(tmp, ft_get_op(op_tmp));
		}
		while (tmp->size > 0)
			ft_arr_push(result, ft_arr_pop(tmp));
	}
	ft_arr_free(&tmp, NULL);
	return (result);
}

t_array *	ft_clean_op(t_array *inst)
{
	t_array *result;
	
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
