/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:46:33 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 03:26:27 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATION_H
# define FT_OPERATION_H

# include "push_swap.h"

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
	NONE
}	t_operator;

int	ft_run_op(t_push_swap *ptr, t_operator op);
int	ft_add_operator(t_push_swap *ps, t_operator op);

#endif
