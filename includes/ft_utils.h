/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:16:13 by gcros             #+#    #+#             */
/*   Updated: 2024/01/16 01:39:21 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include "arr.h"
#include "ft_operation.h"
#include "push_swap.h"
# include "ft_sort.h"

void	ft_put_stack(t_array *array);
void	ft_put_op(t_array *array);
char	*ft_get_op_str(t_operator op);
int		ft_is_sort(t_array *array);
int		ft_dumb_b(t_sort *ps);
int		ft_dumb_a(t_sort *ps);

#endif
