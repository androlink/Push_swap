/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:06:02 by gcros             #+#    #+#             */
/*   Updated: 2024/01/24 16:50:17 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "arr.h"

typedef struct s_push_swap
{
	t_array	*number_set;
	t_array	*results;
}	t_push_swap;

void	ft_ps_exit(t_push_swap *ps, int exit_val);
t_push_swap	ft_ps_get(int ac, char **av);
void		ft_ps_free(t_push_swap	*ps);

#endif
