/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:10:18 by gcros             #+#    #+#             */
/*   Updated: 2025/02/15 18:33:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOAD_H
# define FT_LOAD_H

# include "vector.h"

t_vector	*ft_load(int ac, char **av);
int			normalizer(t_vector **values);
int			ft_check_dup(t_vector *values);

#endif
