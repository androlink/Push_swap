/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:06:24 by gcros             #+#    #+#             */
/*   Updated: 2024/01/10 06:32:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include "str.h"
#include "num.h"
#include "ft_load.h"

static int	*get_value(const char *str);
static int	fill_value(char *str, t_array *array);
static int	check_dup(t_array *array);

t_array	*ft_load(int ac, char **av)
{
	t_array *array;
	int		i;

	i = 0;
	array = ft_arr_new(20);
	if (array == NULL)
		return (NULL);
	while (i < ac)
	{
		if (fill_value(av[i], array) == -1)
			return (ft_arr_free(&array, free), NULL);
		i++;
	}
	if (check_dup(array) == 1 || normalizer(&array) == -1)
		ft_arr_free(&array, free);
	return (array);
}

static int	check_dup(t_array *array)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (*((int *)array->data[i]) == *((int *)array->data[j]))
				return (1);	
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill_value(char *str, t_array *array)
{
	char	**strs;
	int		*value;
	int		i;
	
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (-1);
	i = 0;
	while (strs[i] != NULL)
		i++;
	if (array->capacity <= array->size + i)
		if (ft_arr_resize(array, array->size + i + 1) == -1)
			return (ft_strsfree(strs), -1);
	i = 0;
	while (strs[i] != NULL)
	{
		value = get_value(strs[i]);
		if (value == NULL)
			return (ft_strsfree(strs), -1);
		ft_arr_push(array, value);
		i++;
	}
	ft_strsfree(strs);
	return (1);
}

static int	*get_value(const char *str)
{
	int value;
	int	*ret;

	if (!ft_strisnumber(str) || str[0] == '-')
		return (NULL);
	value = ft_atoi(str);
	if (value == -1)
		return (NULL);
	ret = malloc(sizeof(int));
	if (ret != NULL)
		*ret = value;
	return (ret);
}
