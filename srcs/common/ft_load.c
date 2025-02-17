/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:06:24 by gcros             #+#    #+#             */
/*   Updated: 2025/02/17 08:34:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"
#include "num.h"
#include "ft_load.h"
#include "vector.h"

static int	get_value(const char *str, long *out);
static int	fill_value(char *str, t_vector *values);

t_vector	*ft_load(int ac, char **av)
{
	t_vector	*values;
	int			i;

	i = 0;
	values = ft_vec_new(sizeof(long));
	if (values == NULL)
		return (NULL);
	while (i < ac)
	{
		if (fill_value(av[i], values) == -1)
		{
			ft_vec_free(&values);
			return (NULL);
		}
		i++;
	}
	if (ft_check_dup(values) || normalizer(&values) == -1)
		ft_vec_free(&values);
	return (values);
}

int	ft_check_dup(t_vector *values)
{
	size_t	i;
	size_t	j;
	long	v1;
	long	v2;

	i = 0;
	while (i < values->size)
	{
		j = i + 1;
		while (j < values->size)
		{
			ft_vec_get(values, i, &v1);
			ft_vec_get(values, j, &v2);
			if (v1 == v2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	free_fill(char **strs, int ret_val)
{
	ft_strsfree(strs);
	return (ret_val);
}

static int	fill_value(char *str, t_vector *values)
{
	char	**strs;
	long	value;
	size_t	i;

	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (-1);
	i = 0;
	while (strs[i] != NULL)
		i++;
	if (i == 0)
		return (free_fill(strs, -1));
	if (values->capacity <= values->size + i)
		if (ft_vec_resize(values, values->size + i + 1) == -1)
			return (free_fill(strs, -1));
	i = 0;
	while (strs[i] != NULL)
	{
		if (get_value(strs[i], &value))
			return (free_fill(strs, -1));
		ft_vec_append(values, &value);
		i++;
	}
	return (free_fill(strs, 1));
}

static int	get_value(const char *str, long *out)
{
	long	value;

	if (!ft_strisnumber(str))
		return (1);
	value = ft_atoi(str);
	if (value == -1 && str[0] != '-')
		return (1);
	if (value == 0 && str[0] != '0')
		return (1);
	*out = value;
	return (0);
}
