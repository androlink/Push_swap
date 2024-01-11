/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:56:58 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 03:10:06 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_operation.h"
#include "ft_printf.h"
#include "ft_utils.h"

int	ft_add_operator(t_push_swap *ps, t_operator op)
{
	t_operator	*pop;

	//ft_printf("inst : %d / %d\n", ps->instruction->size, ps->instruction->capacity);
	//ft_printf("stack a : %d / %d\n", ps->stack_a->size, ps->stack_a->capacity);
	//ft_printf("stack b : %d / %d\n", ps->stack_b->size, ps->stack_b->capacity);

	if (ps->instruction->capacity <= ps->instruction->size)
		if (ft_arr_resize(ps->instruction, ps->instruction->capacity + 100) == -1)
			ft_ps_exit(ps, 2);
	pop = malloc(sizeof(t_operator));
	if (pop == NULL)
		ft_ps_exit(ps, 2);
	*pop = op;
	ft_arr_push(ps->instruction, pop);
	return (1);
}

static t_operator	get_op_rev(t_operator op)
{
	static t_operator op_list[] = {SA, SB, PB, PA, RRA, RRB, RA, RB};

	//ft_printf("=== %s >> %s ===\n", ft_get_op_str(op), ft_get_op_str(op_list[op]));
	
	return (op_list[op]);
}
/*
static void	ft_clean_op(t_array *instruction)
{
	size_t	i;

	i = 0;
	
	
}
*/
t_array *	ft_clean_op(t_array *instruction)
{
	t_array *result;
	
	result = ft_arr_new(instruction->size);
	if (result == NULL)
		return (NULL);
	while (instruction->size > 0)
	{
		ft_arr_push(result, ft_arr_pop(instruction));
		while (instruction->size > 0 && result->size > 0 && get_op_rev(*(t_operator *)result->data[result->size - 1]) == *(t_operator *)instruction->data[instruction->size - 1])
		{
			free(ft_arr_pop(instruction));
			free(ft_arr_pop(result));
		}
	}
	return (result);
}
