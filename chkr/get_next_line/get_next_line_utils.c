/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:21:51 by jmartini          #+#    #+#             */
/*   Updated: 2021/02/23 16:24:14 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	it;

	it = 0;
	while (str[it])
		it++;
	return (it);
}

void	*ft_gnl_memcpy(void *dst, const void *src, size_t n)
{
	t_byte			*a;
	const t_byte	*b;

	a = dst;
	b = src;
	if (!dst && !src)
		return (0);
	while (n)
	{
		*a++ = *b++;
		n--;
	}
	return (dst);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	ptr = malloc(sizeof(*ptr) * (ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) + 1);
	if (!ptr)
		return (0);
	ft_gnl_memcpy(ptr, s1, ft_gnl_strlen(s1));
	ft_gnl_memcpy(&ptr[ft_gnl_strlen(s1)], s2, ft_gnl_strlen(s2));
	ptr[ft_gnl_strlen(s1) + ft_gnl_strlen(s2)] = '\0';
	return (ptr);
}

void	*ft_gnl_memset(void *b, int c, size_t len)
{
	t_byte	*ptr;

	ptr = b;
	while (len)
	{
		*ptr = (t_byte)c;
		ptr++;
		len--;
	}
	return (b);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!size)
	{
		ptr = malloc(size);
		return (ptr);
	}
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_gnl_memset(ptr, '\0', size * count);
	return (ptr);
}
