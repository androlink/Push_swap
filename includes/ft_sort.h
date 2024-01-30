/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:26:34 by gcros             #+#    #+#             */
/*   Updated: 2024/01/30 15:19:06 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "arr.h"

typedef struct s_sort
{
	t_array	*stack_a;
	t_array	*stack_b;
	t_array	*instruction;
}	t_sort;

#endif
