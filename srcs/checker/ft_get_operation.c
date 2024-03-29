/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 23:18:36 by gcros             #+#    #+#             */
/*   Updated: 2024/01/30 15:18:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "arr.h"
#include "ft_operation.h"
#include "str.h"
#include "ft_utils.h"

static t_operator	*get_next_operator(void);
t_operator			str_to_operator(char *strop);

t_array	*ft_get_operation(void)
{
	t_array		*op_list;
	t_operator	*tmp;

	op_list = ft_arr_new(20);
	if (op_list == NULL)
		return (NULL);
	tmp = get_next_operator();
	while (tmp != NULL)
	{
		if (*tmp == NONE || ft_add_operator(op_list, *tmp) == -1)
		{
			ft_arr_free(&op_list, NULL);
			return (NULL);
		}
		tmp = get_next_operator();
	}
	return (op_list);
}

static t_operator	*get_next_operator(void)
{
	t_operator	tmp;
	char		*str;

	str = get_next_line(0);
	if (str == NULL)
		return (NULL);
	tmp = str_to_operator(str);
	free(str);
	return (ft_get_op(tmp));
}

t_operator	str_to_operator(char *strop)
{
	if (ft_strncmp(strop, "sa\n", 3) == 0)
		return (SA);
	if (ft_strncmp(strop, "sb\n", 3) == 0)
		return (SB);
	if (ft_strncmp(strop, "pa\n", 3) == 0)
		return (PA);
	if (ft_strncmp(strop, "pb\n", 3) == 0)
		return (PB);
	if (ft_strncmp(strop, "ra\n", 3) == 0)
		return (RA);
	if (ft_strncmp(strop, "rb\n", 3) == 0)
		return (RB);
	if (ft_strncmp(strop, "rra\n", 4) == 0)
		return (RRA);
	if (ft_strncmp(strop, "rrb\n", 4) == 0)
		return (RRB);
	if (ft_strncmp(strop, "ss\n", 3) == 0)
		return (SS);
	if (ft_strncmp(strop, "rr\n", 3) == 0)
		return (RR);
	if (ft_strncmp(strop, "rrr\n", 4) == 0)
		return (RRR);
	return (NONE);
}
