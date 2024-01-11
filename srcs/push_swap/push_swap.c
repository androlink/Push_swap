/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:04:43 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 10:30:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_load.h"
#include "put.h"
#include "ft_utils.h"
#include "ft_operation.h"
#include "push_swap.h"
#include "ft_sort.h"
#include "ft_printf.h"

void	ft_init(int ac, char **av, t_push_swap *ps);
void	ft_print_result(t_array *result);

int	main(int ac, char **av)
{
	t_push_swap	ps;
	t_array *result;

	ft_init(ac - 1, av + 1, &ps);
	ft_new_sort(&ps);
	//ft_radix_sort(&ps);
	//ft_put_op(ps.instruction);//ft_printf("== opti ==\n");
	
	result = ft_clean_op(ps.instruction);
	if (result == NULL)
		ft_ps_exit(&ps, 2);
	ft_print_result(result);
	ft_arr_free(&result, free);
	ft_ps_exit(&ps, 0);
}

void	ft_init(int ac, char **av, t_push_swap *ps)
{
	t_array		*array;

	ps->instruction = NULL;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	if (ac == 0)
		ft_ps_exit(ps, 0);
	array = ft_load(ac, av);
	if (array == NULL)
		ft_ps_exit(ps, 1);
	ps->stack_a = array;
	ps->stack_b = ft_arr_new(array->capacity);
	if (ps->stack_b == NULL)
		ft_ps_exit(ps, 2);
	ps->instruction = ft_arr_new(10);
	if (ps->instruction == NULL)
		ft_ps_exit(ps, 2);
}

void ft_ps_exit(t_push_swap *ps, int exit_val)
{
	if (ps->stack_a != NULL)
		ft_arr_free(&ps->stack_a, free);
	if (ps->stack_b != NULL)
		ft_arr_free(&ps->stack_b, free);
	if (ps->instruction != NULL)
		ft_arr_free(&ps->instruction, free);
	if (exit_val == 1)
		ft_putendl_fd("Error", 2);
	//ft_printf("exit code : %d", exit_val);
	exit(exit_val);
}

void	ft_print_result(t_array *result)
{
	t_operator	*inst;
	
	while (result->size)
	{
		inst = ft_arr_pop(result);
		ft_printf("%s\n", ft_get_op_str(*inst));
		free(inst);
	}
}
