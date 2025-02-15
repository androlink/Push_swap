/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:26:34 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:31:57 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "vector.h"

typedef struct s_sort
{
	t_vector	*stack_a;
	t_vector	*stack_b;
	t_vector	*instruction;
}	t_sort;

#endif
