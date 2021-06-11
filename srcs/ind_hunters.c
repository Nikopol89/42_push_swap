/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_hunters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:07 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:09 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_ind_find_minor(t_stack *stk)
{
	int	i;
	int	j;
	int	candidate;

	i = 0;
	j = 1;
	candidate = 0;
	while (j < stk->size)
	{
		if (stk->arr[i] > stk->arr[j])
		{
			candidate = j;
			i = j;
		}
		j++;
	}
	return (candidate);
}

int	ft_ind_is_next(t_stack *stk, t_data *data)
{
	int	*init;

	if (stk->arr[1] < stk->arr[0])
	{
		init = ft_memint(data->set, stk->arr[0], data->set_size);
		init--;
		if (*init == stk->arr[1])
			return (1);
	}
	return (0);
}

int	ft_ind_is_ordered(t_stack *stk)
{
	int	i;

	i = 0;
	while (i + 1 < stk->size)
	{
		if (stk->arr[i] > stk->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_ind_is_minor(t_stack *stk, int check)
{
	int	i;

	i = 1;
	while (i < stk->size)
	{
		if (check > stk->arr[i])
			return (0);
		i++;
	}
	return (1);
}
