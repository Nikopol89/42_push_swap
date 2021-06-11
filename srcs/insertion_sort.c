/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:23 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:24 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap_sort(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_ins_sort(int *src, int size)
{
	int	i;
	int	j;
	int	candidate;
	int	*array;

	i = 0;
	array = ft_calloc(size, sizeof(*src));
	if (!array)
		return (0);
	ft_memcpy(array, src, sizeof(*array) * size);
	while (i < (size - 1))
	{
		candidate = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[candidate])
				candidate = j;
			j++;
		}
		ft_swap_sort(&array[candidate], &array[i]);
		i++;
	}
	return (array);
}
