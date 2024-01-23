/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:04:43 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 12:10:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_print_result(t_array *result);
void	ft_print_best_result(t_array *results);

int	main(int ac, char **av)
{
	t_push_swap	*ps;
	t_array		*result;

	if (ac < 2)
		exit (0);
	ps = ft_ps_init(ac - 1, av + 1);
	if (ps == NULL)
		ft_ps_exit(-1);
	result = ft_sort(ps->number_set, &ft_sort_3);
	if (result != NULL)
		ft_arr_push(ps->results, result);
	result = ft_sort(ps->number_set, &ft_radix_sort);
	if (result != NULL)
		ft_arr_push(ps->results, result);
	result = ft_sort(ps->number_set, &ft_quad_insert_with_pivot);
	if (result != NULL)
		ft_arr_push(ps->results, result);
	result = ft_sort(ps->number_set, &ft_quad_insert);
	if (result != NULL)
		ft_arr_push(ps->results, result);
	result = ft_sort(ps->number_set, &ft_double_insert_sort);
	if (result != NULL)
		ft_arr_push(ps->results, result);
	ft_print_best_result(ps->results);
	ft_ps_exit(0);
}

void	ft_ps_exit(int exit_val)
{
	ft_ps_destroy();
	exit(exit_val);
}

void	ft_print_best_result(t_array *results)
{
	size_t	i;
	t_array	*result;

	i = 0;
	result = NULL;
	while (i < results->size)
	{
		if (result == NULL)
			result = (t_array *)results->data[i];
		if (result->size > ((t_array *)(results->data[i]))->size)
		{
			result = (t_array *)(results->data[i]);
		}
		i++;
	}
	if (result == NULL)
		return ;
	ft_print_result(result);
}

void	ft_print_result(t_array *result)
{
	size_t	i;

	i = 0;
	while (i < result->size)
	{
		ft_printf("%s\n", ft_get_op_str(*(t_operator *)result->data[i]));
		i++;
	}
}
