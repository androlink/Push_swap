/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:41:05 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:12:09 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_load.h"
#include "put.h"

static t_push_swap	**ft_push_swap(void);

t_push_swap	*ft_ps_init(int ac, char **av)
{
	t_push_swap	*ps;

	ps = ft_ps_get();
	if (ps == NULL)
		return (NULL);
	ps->number_set = ft_load(ac, av);
	if (ps->number_set == NULL)
	{
		free(ps);
		ft_putendl_fd("Error", 2);
		exit(-1);
	}
	ps->results = ft_arr_new(10);
	if (ps->results == NULL)
		return (NULL);
	return (ps);
}

t_push_swap	*ft_ps_get(void)
{
	t_push_swap	**ps;

	ps = ft_push_swap();
	if (*ps == NULL)
		*ps = malloc(sizeof(t_push_swap));
	return (*ps);
}

static void	free_ps_result(void *array)
{
	t_array	*arr;

	arr = (t_array *)array;
	ft_arr_free(&arr, NULL);
}

void	ft_ps_destroy(void)
{
	t_push_swap	**ps;

	ps = ft_push_swap();
	if (*ps == NULL)
		return ;
	ft_arr_free(&(*ps)->number_set, free);
	ft_arr_free(&(*ps)->results, free_ps_result);
	free(*ps);
	*ps = NULL;
}

static t_push_swap	**ft_push_swap(void)
{
	static t_push_swap	*ps;

	return (&ps);
}
