/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkrs_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:40 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:42 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_calc_a(t_data *data, t_stack *stk_a, t_stack *stk_b)
{
	if (stk_b->size == data->sub_size + (data->sub_pos * data->sub_size))
		data->sub_pos++;
	data->opt_pos = ft_opt_submemb(data, stk_a);
	if (data->opt_pos < (float)(stk_a->size / 2))
		data->ops->ra = data->opt_pos;
	else
		data->ops->rra = stk_a->size - data->opt_pos;
}

static void	ft_calc_b(t_data *data, t_stack *stk_a, t_stack *stk_b)
{
	int	pos;
	int	*pos_addr;

	if (stk_b->size < 2)
		return ;
	pos_addr = ft_ordered_position(stk_b, data, stk_a->arr[data->opt_pos]);
	if (pos_addr)
	{
		pos = pos_addr - stk_b->arr;
		if (pos < (float)(stk_b->size / 2))
			data->ops->rb = pos;
		else
			data->ops->rrb = stk_b->size - pos;
	}
	else if (stk_b->size)
	{
		pos_addr = ft_find_biggest(stk_b);
		pos = pos_addr - stk_b->arr;
		if (pos < (float)(stk_b->size / 2))
			data->ops->rb = pos;
		else
			data->ops->rrb = stk_b->size - pos;
	}
}

static void	ft_calc_double(t_data *data)
{
	while (data->ops->ra && data->ops->rb)
	{
		data->ops->ra--;
		data->ops->rb--;
		data->ops->rr++;
	}
	while (data->ops->rra && data->ops->rrb)
	{
		data->ops->rra--;
		data->ops->rrb--;
		data->ops->rrr++;
	}
}

void	ft_order_b(t_data *data, t_stack *stk_b)
{
	int	pos;
	int	*pos_addr;

	if (stk_b->size < 2)
		return ;
	pos_addr = ft_find_biggest(stk_b);
	if (pos_addr)
	{
		pos = pos_addr - stk_b->arr;
		if (pos < (float)(stk_b->size / 2))
			data->ops->rb = pos;
		else
			data->ops->rrb = stk_b->size - pos;
	}
	else if (stk_b->size)
	{
		pos_addr = ft_find_biggest(stk_b);
		pos = pos_addr - stk_b->arr;
		if (pos < (float)(stk_b->size / 2))
			data->ops->rb = pos;
		else
			data->ops->rrb = stk_b->size - pos;
	}
}

void	ft_rkrs_calc(t_stack *stk_a, t_stack *stk_b, t_data *data)
{
	ft_calc_a(data, stk_a, stk_b);
	ft_calc_b(data, stk_a, stk_b);
	ft_calc_double(data);
}
