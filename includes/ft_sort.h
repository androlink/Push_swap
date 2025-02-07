/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:26:34 by gcros             #+#    #+#             */
/*   Updated: 2025/02/06 18:58:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "arr.h"
# include "vector.h"

typedef struct s_sort
{
	t_vector	*stack_a;
	t_vector	*stack_b;
	t_array		*instruction;
}	t_sort;

#endif
