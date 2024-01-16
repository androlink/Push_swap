/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:26:34 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 04:57:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

#include "arr.h"

typedef struct s_sort
{
	t_array *stack_a;
	t_array *stack_b;
	t_array *instruction;
}	t_sort;

t_array	*ft_sort(t_array *num_set, int (*fsort)(t_sort *));

int	ft_sort_2(t_sort *ps);
int ft_radix_sort(t_sort *ps);
int	ft_double_insert_sort(t_sort *ps);
int ft_quad_insert(t_sort *ps);
int ft_quad_insert_with_pivot(t_sort *ps);

int ft_goto_a(t_sort *ps, size_t pos);
size_t	ft_get_dist(t_array *array, size_t index);
ssize_t	ft_find_value(t_array *arr, int value);
int ft_goto_b(t_sort *ps, size_t pos);

t_array *ft_clean_op(t_array *instruction);
t_array	*ft_merge_op(t_array *inst);

#endif
