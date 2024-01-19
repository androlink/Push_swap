/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:16:41 by gcros             #+#    #+#             */
/*   Updated: 2024/01/19 17:15:29 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operation.h"
#include "ft_utils.h"

int	ft_sort_2(t_sort *ps)
{
	if (!ft_is_sort(ps->stack_a))
		if (ft_run_op(ps, RA))
			if (ft_add_operator(ps->instruction, RA) == -1)
				return (-1);
	return (1);
}
