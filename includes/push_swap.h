/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:06:02 by gcros             #+#    #+#             */
/*   Updated: 2024/01/07 20:01:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "arr.h"
#include "ft_operation.h"

typedef struct s_push_swap
{
	t_array *stack_a;
	t_array *stack_b;
	t_array *operation;
	union
	{
		t_operation *op_func[2];
		struct
		{
			t_operation *operations;
			t_operation *reverse_op;
		};
	};
}	t_push_swap;



#endif