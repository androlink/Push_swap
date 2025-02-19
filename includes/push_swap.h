/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:06:02 by gcros             #+#    #+#             */
/*   Updated: 2025/02/19 20:51:37 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "vector.h"
# include "ft_sort.h"
# include "arr.h"

# define IGNORE_DOUBLE_INSERT 0
# define VERBOSE_RESULT 1

typedef struct s_push_swap
{
	t_vector	*number_set;
	t_array		*results;
}	t_push_swap;

typedef int(*	t_sortf)(t_sort *);

void		ft_ps_exit(t_push_swap *ps, int exit_val);
t_push_swap	ft_ps_get(int ac, char **av);
void		ft_ps_free(t_push_swap *ps);

t_vector	*ft_sort(t_vector *num_set, int (*fsort)(t_sort *));

int			ft_radix_sort(t_sort *sort);
int			ft_double_insert_sort(t_sort *sort);
int			ft_quad_insert(t_sort *sort);
int			ft_quad_insert_with_pivot(t_sort *sort);
int			ft_sort_3(t_sort *srt);
int			ps_stalinsort(t_sort *sort);

int			ft_goto_a(t_sort *sort, size_t pos);
size_t		ft_get_dist(t_vector *stack, size_t index);
ssize_t		ft_find_value(t_vector *stack, int value);
int			ft_goto_b(t_sort *sort, size_t pos);

t_vector	*ft_clean_op(t_vector *instruction);
t_vector	*ft_merge_op(t_vector *inst);

int			ft_dump_b(t_sort *sort);
int			ft_dump_a(t_sort *sort);

void		ft_print_result(t_vector *result);
int			ft_run_sort(t_push_swap *ps, const t_sortf fsort);

#endif
