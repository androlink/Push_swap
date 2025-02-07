/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:16:13 by gcros             #+#    #+#             */
/*   Updated: 2025/02/06 19:00:49 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "arr.h"
# include "ft_sort.h"
# include "ft_operation.h"

char	*ft_get_op_str(t_operator op);
int		ft_is_sort(t_vector *array);

#endif
