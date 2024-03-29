/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:06:02 by gcros             #+#    #+#             */
/*   Updated: 2024/02/01 01:06:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "arr.h"
# include "ft_sort.h"

typedef struct s_push_swap
{
	t_array	*number_set;
	t_array	*results;
}	t_push_swap;

void		ft_ps_exit(t_push_swap *ps, int exit_val);
t_push_swap	ft_ps_get(int ac, char **av);
void		ft_ps_free(t_push_swap *ps);

t_array		*ft_sort(t_array *num_set, int (*fsort)(t_sort *));

int			ft_radix_sort(t_sort *sort);
int			ft_double_insert_sort(t_sort *sort);
int			ft_quad_insert(t_sort *sort);
int			ft_quad_insert_with_pivot(t_sort *sort);
int			ft_sort_3(t_sort *srt);

int			ft_goto_a(t_sort *sort, size_t pos);
size_t		ft_get_dist(t_array *array, size_t index);
ssize_t		ft_find_value(t_array *arr, int value);
int			ft_goto_b(t_sort *sort, size_t pos);

t_array		*ft_clean_op(t_array *instruction);
t_array		*ft_merge_op(t_array *inst);

int			ft_dump_b(t_sort *sort);
int			ft_dump_a(t_sort *sort);

void		ft_print_result(t_array *result);

#endif
