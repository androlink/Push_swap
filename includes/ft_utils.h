/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:16:13 by gcros             #+#    #+#             */
/*   Updated: 2024/02/01 01:17:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "arr.h"
# include "ft_sort.h"
# include "ft_operation.h"

char	*ft_get_op_str(t_operator op);
int		ft_is_sort(t_array *array);

#endif
