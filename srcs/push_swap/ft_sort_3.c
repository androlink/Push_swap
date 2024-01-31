/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:49 by gcros             #+#    #+#             */
/*   Updated: 2024/01/30 15:11:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_utils.h"
#include "push_swap.h"
#include <unistd.h>

int	ft_sort_3(t_sort *srt)
{
	if (srt->stack_a->size < 3)
		return (0);
	if (*(long *)srt->stack_a->data[1] == 2)
		if (ft_run_op(srt, SA))
			if (ft_add_operator(srt->instruction, SA) == -1)
				return (-1);
	if (*(long *)srt->stack_a->data[0] == 2)
		if (ft_run_op(srt, RA))
			if (ft_add_operator(srt->instruction, RA) == -1)
				return (-1);
	if (*(long *)srt->stack_a->data[0] > *(long *)srt->stack_a->data[1])
		if (ft_run_op(srt, SA))
			if (ft_add_operator(srt->instruction, SA) == -1)
				return (-1);
	return (1);
}
