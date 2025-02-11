/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:35:41 by gcros             #+#    #+#             */
/*   Updated: 2025/02/11 14:50:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_operation.h"

t_vector	*ft_get_operation(void);
int			ft_apply_op(t_sort *sort);

#endif
