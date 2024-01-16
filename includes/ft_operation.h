/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:46:33 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 01:35:08 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "ft_sort.h"

typedef enum e_operator
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	NONE,
	SS,
	RR,
	RRR
}	t_operator;

int	ft_run_op(t_sort *ptr, t_operator op);
int	ft_add_operator(t_array *instruction, t_operator op);

t_operator	ft_get_op_rev(t_operator op);
t_operator	*ft_get_op(t_operator op);
t_operator	ft_get_merge_op(t_operator op1, t_operator op2);
t_operator	ft_get_last_op(t_array *array);
size_t	ft_get_min(t_array *array);

#endif
