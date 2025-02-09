/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:05:15 by gcros             #+#    #+#             */
/*   Updated: 2025/02/09 18:41:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "vector.h"
#include "put.h"
#include "push_swap.h"

void	print_info(t_sortf fsort, int has_fail, t_array *result);

int	ft_run_sort(t_push_swap *ps, const t_sortf fsort)
{
	t_array	*result;

	result = ft_sort(ps->number_set, fsort);
	if (result != NULL)
	{
		if (ft_arr_push(ps->results, result) == 0)
			ft_arr_free(&ps->results, NULL);
	}
	if (VERBOSE_RESULT)
		print_info(fsort, result == NULL, result);
	return (0);
}

const char	*get_name(t_sortf fsort)
{
	if (fsort == ft_sort_3)
		return ("ft_sort_3");
	if (fsort == ft_radix_sort)
		return ("ft_radix_sort");
	if (fsort == ft_double_insert_sort)
		return ("ft_double_insert_sort");
	if (fsort == ft_quad_insert)
		return ("ft_quad_insert");
	if (fsort == ft_quad_insert_with_pivot)
		return ("ft_quad_insert_with_pivot");
	if (fsort == ps_stalinsort)
		return ("ps_stalinsort");
	return ("unknown_sort");
}

void	print_info(t_sortf fsort, int has_fail, t_array *result)
{
	const char	*name = get_name(fsort);

	ft_putstr_fd((char *)name, 2);
	if (has_fail)
	{
		ft_putstr_fd(" has fail to sort numbers\n", 2);
	}
	else
	{
		ft_putstr_fd(" sort in ", 2);
		ft_putnbr_fd(result->size, 2);
		ft_putstr_fd(" instructions\n", 2);
	}
}
