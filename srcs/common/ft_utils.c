/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:34 by gcros             #+#    #+#             */
/*   Updated: 2024/01/07 14:23:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "arr.h"
#include "put.h"

void	ft_put_stack(t_array *array)
{
	size_t	i;

	i = 0;
	while (i < array->size)
	{
		ft_putnbr_fd((*((int *)array->data[i])), 1);
		write(1, ", ", 2);
		i++;
	}
	write(1, "\n", 1);
}