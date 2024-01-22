/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:05:08 by gcros             #+#    #+#             */
/*   Updated: 2024/01/22 01:51:18 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_load.h"
#include "checker.h"
#include "ft_utils.h"
#include "ft_printf.h"
#include "put.h"

t_sort	*checker_init(int ac, char **av);
void	free_sort(t_sort *sort);

int	main(int ac, char **av)
{
	t_sort	*sort;
	int res;

	if (ac == 1)
		return (0);
	sort = checker_init(ac - 1, av + 1);
	if (sort == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	res = ft_apply_op(sort);
	free_sort(sort);
	if (res == -1)
		ft_putstr_fd("Error\n", 2);
	if (res == 0)
		ft_putstr_fd("KO\n", 1);
	if (res == 1)
		ft_putstr_fd("OK\n", 1);
	return (0);
}

void	free_sort(t_sort *sort)
{
	ft_arr_free(&sort->instruction, NULL);
	ft_arr_free(&sort->stack_a, free);
	ft_arr_free(&sort->stack_b, free);
	free(sort);
}
t_sort	*checker_init(int ac, char **av)
{
	t_sort *sort;

	sort = malloc(sizeof(t_sort));
	if (sort == NULL)
		return (NULL);
	sort->stack_b = NULL;
	sort->instruction = NULL;
	sort->stack_a = ft_load(ac, av);
	sort->instruction = ft_get_operation();
	if (sort->stack_a != NULL)
		sort->stack_b = ft_arr_new(sort->stack_a->size);
	if (sort->stack_a == NULL || sort->stack_b == NULL || sort->instruction == NULL)
	{
		if (sort->instruction != NULL)
			ft_arr_free(&sort->instruction, NULL);
		if (sort->stack_a != NULL)
			ft_arr_free(&sort->stack_a, free);
		if (sort->stack_b != NULL)
			ft_arr_free(&sort->stack_b, free);
		ft_nfree((void **)&sort);
	}
	return (sort);
}
