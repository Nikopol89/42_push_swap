/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkrs_hunters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:47 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:48 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_find_biggest(t_stack *stk)
{
	int	i;
	int	j;
	int	*candidate;

	i = 0;
	j = 1;
	candidate = &stk->arr[i];
	while (j < stk->size)
	{
		if (stk->arr[i] < stk->arr[j])
		{
			candidate = &stk->arr[j];
			i = j;
		}
		j++;
	}
	return (candidate);
}

int	*ft_ordered_position(t_stack *stk, t_data *data, int c)
{
	int	*c_addr;
	int	*tmp;

	c_addr = ft_memint(data->set, c, data->set_size);
	if (c_addr != data->set)
	{	
		tmp = c_addr;
		while (tmp >= data->set && tmp)
		{
			if (ft_memint(stk->arr, *tmp, stk->size))
				return (ft_memint(stk->arr, *tmp, stk->size));
			tmp--;
		}
	}
	return (0);
}

int	ft_opt_submemb(t_data *data, t_stack *stk)
{
	int	i;
	int	j;

	i = 0;
	j = stk->size - 1;
	while (i < stk->size && j)
	{
		if ((ft_memint(data->set + (data->sub_pos * data->sub_size),
					stk->arr[i], data->sub_size)))
			return (i);
		if ((ft_memint(data->set + (data->sub_pos * data->sub_size),
					stk->arr[j], data->sub_size)))
			return (j);
		j--;
		i++;
	}
	return (-1);
}
