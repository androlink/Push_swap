/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:04:43 by gcros             #+#    #+#             */
/*   Updated: 2024/01/07 19:34:20 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_load.h"
#include "put.h"
#include "ft_utils.h"

int	sort(t_array *);


int	main(int ac, char **av)
{
	t_array	*array;

	if (ac == 1)
		return (0);
	array = ft_load(ac - 1, &av[1]);
	if (array == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	
	ft_put_stack(array);
	ft_arr_free(&array, free);
	
	return (0);
}
