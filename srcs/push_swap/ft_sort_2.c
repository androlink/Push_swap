/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:16:41 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 16:58:06 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_utils.h"

int	ft_sort_2(t_sort *sort)
{
	if (!ft_is_sort(sort->stack_a))
		if (ft_run_op(sort, RA))
			if (ft_add_operator(sort->instruction, RA) == -1)
				return (-1);
	return (1);
}
