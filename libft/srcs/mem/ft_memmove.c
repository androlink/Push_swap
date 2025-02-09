/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:43:18 by gcros             #+#    #+#             */
/*   Updated: 2025/02/09 20:04:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static inline void	*ft_memmove_foreward(void *dest, const void *src, size_t n);
static inline void	*ft_memmove_backward(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return (ft_memmove_foreward(dest, src, n));
	else if (dest > src)
		return (ft_memmove_backward(dest, src, n));
	return (dest);
}

static inline void	*ft_memmove_backward(void *dest, const void *src, size_t n)
{
	size_t	mod;

	mod = n % 8;
	while (mod--)
	{
		n--;
		((char *)dest)[n] = ((char *)src)[n];
	}
	n /= 8;
	while (n--)
	{
		((size_t *)dest)[n] = ((size_t *)src)[n];
	}
	return (dest);
}

static inline void	*ft_memmove_foreward(void *dest, const void *src, size_t n)
{
	const size_t	n_copy = n / 8;
	size_t			index;

	index = 0;
	while (index < n_copy)
	{
		((size_t *)dest)[index] = ((size_t *)src)[index];
		index++;
	}
	index *= 8;
	while (index < n)
	{
		((char *)dest)[index] = ((char *)src)[index];
		index++;
	}
	return (dest);
}
