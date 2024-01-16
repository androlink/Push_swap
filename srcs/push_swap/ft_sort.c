/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:08:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 04:58:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_sort.h"


void	*ft_pdup(void *ptr)
{
	return (ptr);
}

t_array	*ft_sort(t_array *num_set, int (*fsort)(t_sort *))
{
	t_array *clean_result;
	t_array *merged_result;
	t_sort	sort;
	
	sort.stack_a = ft_arr_map(num_set, ft_pdup, NULL);
	sort.stack_b = ft_arr_new(num_set->capacity);
	sort.instruction = ft_arr_new(20);
	merged_result = NULL;
	if (sort.stack_a != NULL && sort.stack_b != NULL && sort.instruction != NULL)
	{
		if (fsort(&sort) == 1)
		{
			clean_result = ft_clean_op(sort.instruction);
			if (clean_result != NULL)
				merged_result = ft_merge_op(clean_result);
			ft_arr_free(&clean_result, NULL);
		}
	}
	ft_arr_free(&sort.stack_a, NULL);
	ft_arr_free(&sort.stack_b, NULL);
	ft_arr_free(&sort.instruction, NULL);
	return (merged_result);
}
