/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:06:02 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 03:35:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "arr.h"

typedef struct s_push_swap
{
	t_array *stack_a;
	t_array *stack_b;
	t_array *instruction;
}	t_push_swap;

void ft_ps_exit(t_push_swap *ps, int exit_val);
t_array *	ft_clean_op(t_array *instruction);
#endif
