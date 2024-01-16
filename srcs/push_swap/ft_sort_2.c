/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:16:41 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 01:46:56 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "arr.h"
#include "ft_utils.h"
#include "ft_sort.h"
#include "put.h"
#include <stdio.h>
#include "ft_printf.h"

int	ft_sort_2(t_sort *ps)
{
	if (!ft_is_sort(ps->stack_a))
		if (ft_run_op(ps, RA))
				if (ft_add_operator(ps->instruction, RA) == -1)
					return (-1);
	return (1);
}
