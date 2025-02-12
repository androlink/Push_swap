/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:56:58 by gcros             #+#    #+#             */
/*   Updated: 2025/02/12 18:55:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"

static int	ft_merge_brain(t_vector *inst,
				t_vector *result,
				t_vector *tmp);

t_vector	*ft_merge_op(t_vector *inst)
{
	t_vector	*result;
	t_vector	*tmp;

	result = ft_vec_new(inst->elem_size);
	tmp = ft_vec_new(inst->elem_size);
	if (result == NULL || tmp == NULL || ft_vec_resize(result, inst->size) == 0
		||ft_vec_resize(tmp, inst->size) == 0)
		return (ft_vec_free(&tmp), ft_vec_free(&result), NULL);
	while (inst->size > 0)
		ft_merge_brain(inst, result, tmp);
	return (ft_vec_free(&tmp), result);
}

static inline int	ft_merge_brain(t_vector *inst,
	t_vector *result,
	t_vector *tmp)
{
	t_operator	op_tmp;
	t_operator	void_op;

	ft_vec_pop(inst, &op_tmp);
	ft_vec_push(result, &op_tmp);
	while (inst->size > 0 && result->size > 0)
	{
		op_tmp = ft_get_merge_op(ft_get_last_op(result),
				ft_get_last_op(inst));
		if (op_tmp == NONE)
			break ;
		ft_vec_pop(inst, &void_op);
		ft_vec_pop(result, &void_op);
		ft_vec_push(tmp, &op_tmp);
	}
	while (tmp->size > 0)
	{
		ft_vec_pop(tmp, &op_tmp);
		ft_vec_push(result, &op_tmp);
	}
	return (0);
}

t_vector	*ft_clean_op(t_vector *inst)
{
	t_vector	*result;
	t_operator	tmp;

	result = ft_vec_new(inst->elem_size);
	if (result == NULL || ft_vec_resize(result, inst->size) == 0)
		return (NULL);
	while (inst->size > 0)
	{
		ft_vec_pop(inst, &tmp);
		ft_vec_push(result, &tmp);
		while (inst->size > 0 && result->size > 0
			&& ft_get_op_rev(((t_operator *)result->data)[result->size - 1])
			== ((t_operator *)inst->data)[inst->size - 1])
		{
			ft_vec_pop(inst, &tmp);
			ft_vec_pop(result, &tmp);
		}
	}
	return (result);
}

int	ft_dump_b(t_sort *sort)
{
	while (sort->stack_b->size > 0)
	{
		if (ft_run_op(sort, PA) == 1)
			if (ft_add_operator(sort->instruction, PA) == -1)
				return (-1);
	}
	return (1);
}

int	ft_dump_a(t_sort *sort)
{
	while (sort->stack_a->size > 0)
	{
		if (ft_run_op(sort, PB) == 1)
			if (ft_add_operator(sort->instruction, PB) == -1)
				return (-1);
	}
	return (1);
}
