/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:46:33 by gcros             #+#    #+#             */
/*   Updated: 2024/01/07 19:59:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

#include "arr.h"
#include "push_swap.h"

typedef enum e_operator
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB
}	t_operator;



typedef void t_operation(t_array*);

int	ft_op_init(t_push_swap *);

t_operation ft_op_swap;

#endif