/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:05:08 by gcros             #+#    #+#             */
/*   Updated: 2024/02/01 01:27:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "ft_load.h"
#include "checker.h"
#include "put.h"

static t_sort	*checker_init(int ac, char **av);
static void		free_sort(t_sort *sort);

int	main(int ac, char **av)
{
	t_sort	*sort;
	int		res;

	res = 1;
	if (ac == 1)
		return (0);
	sort = checker_init(ac - 1, av + 1);
	if (sort == NULL)
		res = -1;
	if (res != -1)
	{
		res = ft_apply_op(sort);
		free_sort(sort);
	}
	if (res == -1)
		ft_putstr_fd("Error\n", 2);
	if (res == 0)
		ft_putstr_fd("KO\n", 1);
	if (res == 1)
		ft_putstr_fd("OK\n", 1);
	return (0);
}

static void	free_sort(t_sort *sort)
{
	if (sort->instruction != NULL)
		ft_arr_free(&sort->instruction, NULL);
	if (sort->stack_a != NULL)
		ft_arr_free(&sort->stack_a, free);
	if (sort->stack_b != NULL)
		ft_arr_free(&sort->stack_b, free);
	free(sort);
}

static t_sort	*checker_init(int ac, char **av)
{
	t_sort	*sort;

	sort = malloc(sizeof(t_sort));
	if (sort == NULL)
		return (NULL);
	sort->stack_b = NULL;
	sort->instruction = NULL;
	sort->stack_a = ft_load(ac, av);
	if (sort->stack_a != NULL)
		sort->instruction = ft_get_operation();
	if (sort->stack_a != NULL)
		sort->stack_b = ft_arr_new(sort->stack_a->size);
	if (sort->stack_a == NULL
		|| sort->stack_b == NULL
		|| sort->instruction == NULL)
	{
		free_sort(sort);
		sort = NULL;
	}
	return (sort);
}
