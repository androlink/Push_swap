/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quad_insert_with_pivot.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:01:02 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:29:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUAD_INSERT_WITH_PIVOT_H
# define FT_QUAD_INSERT_WITH_PIVOT_H

# include <unistd.h>

typedef struct s_cost
{
	size_t	cost;
	size_t	index_a;
	size_t	index_b;
}	t_cost;

t_cost	get_cost(t_sort *sort, size_t index);
t_cost	get_best_move(t_sort *sort);
int		turc_side_sort(t_sort *sort);

#endif