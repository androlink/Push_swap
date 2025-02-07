/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:08:13 by gcros             #+#    #+#             */
/*   Updated: 2025/02/06 22:23:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_utils.h"
#include "push_swap.h"

t_vector	*dup_numset(t_vector *values)
{
	t_vector	*dup_val;

	dup_val = malloc(sizeof(t_vector));
	if (dup_val != NULL)
	{
		dup_val->elem_size = values->elem_size;
		dup_val->capacity = values->size;
		dup_val->size = values->size;
		dup_val->data = malloc(dup_val->elem_size * dup_val->size);
		if (dup_val->data == NULL)
		{
			free(dup_val);
			return (NULL);
		}
		ft_memcpy(dup_val->data,
			values->data,
			dup_val->size * dup_val->elem_size);
	}
	return (dup_val);
}

static void	free_sort(t_sort *sort)
{
	if (sort->instruction != NULL)
		ft_arr_free(&sort->instruction, NULL);
	if (sort->stack_a != NULL)
		ft_vec_free(&sort->stack_a);
	if (sort->stack_b != NULL)
		ft_vec_free(&sort->stack_b);
	sort->instruction = NULL;
	sort->stack_b = NULL;
	sort->stack_a = NULL;
}

static t_sort	get_sort(t_vector *num_set)
{
	t_sort	sort;

	sort.stack_a = dup_numset(num_set);
	sort.stack_b = dup_numset(num_set);
	sort.instruction = ft_arr_new(20);
	if (sort.stack_b != NULL)
		sort.stack_b->size = 0;
	if (sort.instruction == NULL
		|| sort.stack_a == NULL
		|| sort.stack_b == NULL)
		free_sort(&sort);
	return (sort);
}

t_array	*ft_sort(t_vector *num_set, int (*fsort)(t_sort *))
{
	t_array	*clean_result;
	t_array	*merged_result;
	t_sort	sort;

	sort = get_sort(num_set);
	if (sort.instruction == NULL)
		return (NULL);
	merged_result = NULL;
	if (fsort(&sort) == 1
		&& ft_is_sort(sort.stack_a) && sort.stack_b->size == 0)
	{
		clean_result = ft_clean_op(sort.instruction);
		if (clean_result != NULL)
		{
			merged_result = ft_merge_op(clean_result);
			ft_arr_free(&clean_result, NULL);
		}
	}
	free_sort(&sort);
	return (merged_result);
}
