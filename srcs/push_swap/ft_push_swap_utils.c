/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:41:05 by gcros             #+#    #+#             */
/*   Updated: 2025/02/09 18:25:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_load.h"

t_push_swap	ft_ps_get(int ac, char **av)
{
	t_push_swap	ps;

	ps.results = NULL;
	ps.number_set = ft_load(ac, av);
	if (ps.number_set == NULL)
		return (ps);
	ps.results = ft_arr_new(20);
	if (ps.results == NULL)
		ft_vec_free(&ps.number_set);
	return (ps);
}

static void	free_ps_result(void *array)
{
	t_array	*arr;

	arr = (t_array *)array;
	ft_arr_free(&arr, NULL);
}

void	ft_ps_free(t_push_swap	*ps)
{
	if (ps->number_set != NULL)
		ft_vec_free(&ps->number_set);
	if (ps->results != NULL)
		ft_arr_free(&ps->results, free_ps_result);
	ps->number_set = NULL;
	ps->results = NULL;
}
