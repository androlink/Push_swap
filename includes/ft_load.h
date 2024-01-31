/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:10:18 by gcros             #+#    #+#             */
/*   Updated: 2024/01/23 16:50:15 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOAD_H
# define FT_LOAD_H

# include "arr.h"

t_array	*ft_load(int ac, char **av);
int		normalizer(t_array **array);
int		ft_check_dup(t_array *array);

#endif
