/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:04:43 by gcros             #+#    #+#             */
/*   Updated: 2025/02/07 22:01:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "push_swap.h"
#include "put.h"
#include "ft_printf.h"

static void	ft_print_best_result(t_array *results);

int	main(int ac, char **av)
{
	t_push_swap		ps;
	t_array			*result;
	const t_sortf	f_list[] = {&ft_sort_3, &ft_radix_sort,
		&ft_quad_insert_with_pivot, &ft_quad_insert,
		&ft_double_insert_sort, &ps_stalinsort};
	size_t			i;

	if (ac < 2)
		exit (0);
	ps = ft_ps_get(ac - 1, av + 1);
	if (ps.number_set == NULL || ps.results == NULL)
		ft_ps_exit(&ps, -1);
	i = 0;
	while (i < sizeof(f_list) / sizeof(*f_list))
	{
		result = ft_sort(ps.number_set, f_list[i]);
		if (result != NULL)
			ft_arr_push(ps.results, result);
		i++;
	}
	ft_print_best_result(ps.results);
	ft_ps_exit(&ps, 0);
}

void	ft_ps_exit(t_push_swap *ps, int exit_val)
{
	ft_ps_free(ps);
	if (exit_val == -1)
		ft_putstr_fd("Error\n", 2);
	exit(exit_val);
}

static void	ft_print_best_result(t_array *results)
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
		if (ft_printf("%s\n",
				ft_get_op_str(*(t_operator *)result->data[i])) == -1)
			return ;
		i++;
	}
}
