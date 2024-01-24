/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:08:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/24 18:55:20 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_utils.h"

void	*ft_pdup(void *ptr)
{
	return (ptr);
}

static void	free_sort(t_sort *sort)
{
	if (sort->instruction != NULL)
		ft_arr_free(&sort->instruction, NULL);
	if (sort->stack_a != NULL)
		ft_arr_free(&sort->stack_a, NULL);
	if (sort->stack_b != NULL)
		ft_arr_free(&sort->stack_b, NULL);
	sort->instruction = NULL;
	sort->stack_b = NULL;
	sort->stack_a = NULL;
}

static t_sort	get_sort(t_array *num_set)
{
	t_sort	sort;

	sort.stack_a = ft_arr_map(num_set, ft_pdup, NULL);
	sort.stack_b = ft_arr_new(num_set->capacity);
	sort.instruction = ft_arr_new(20);
	if (sort.instruction == NULL
		|| sort.stack_a == NULL
		|| sort.stack_b == NULL)
		free_sort(&sort);
	return (sort);
}

t_array	*ft_sort(t_array *num_set, int (*fsort)(t_sort *))
{
	t_array	*clean_result;
	t_array	*merged_result;
	t_sort	sort;

	sort = get_sort(num_set);
	if (sort.instruction == NULL)
		return (NULL);
	merged_result = NULL;
	if (fsort(&sort) == 1 && ft_is_sort(sort.stack_a))
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
