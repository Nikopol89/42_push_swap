/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:20:19 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:20:21 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_engine(t_stack *stk_a, t_stack *stk_b, t_data *data, int vr)
{
	t_ops	ops;

	data->ops = &ops;
	while (stk_b->size < data->sub_size * (data->sub_cnt - 1))
	{
		ft_init_ops(data);
		ft_rkrs_calc(stk_a, stk_b, data);
		ft_exec_ops(data, stk_a, stk_b, vr);
		ft_push(stk_a, stk_b);
		data->total_ops++;
		if (!vr)
			ft_printf("pb\n");
	}
	ft_init_ops(data);
	ft_order_b(data, stk_b);
	ft_exec_ops(data, stk_a, stk_b, vr);
	ft_ind_calc(stk_a, stk_b, data, vr);
}

void	ft_prophet(t_stack *init, t_stack *stk_a, t_stack *stk_b, t_data *data)
{
	int	candidate;
	int	prophecy;

	while (data->sub_size <= 50)
	{
		ft_re_init(init, stk_a, stk_b, data);
		ft_engine(stk_a, stk_b, data, 1);
		if (data->sub_size == 10)
		{
			candidate = data->total_ops;
			prophecy = data->sub_size;
		}
		if (data->total_ops < candidate)
		{
			candidate = data->total_ops;
			prophecy = data->sub_size;
		}
		data->sub_size++;
	}
	data->sub_size = prophecy;
	ft_re_init(init, stk_a, stk_b, data);
	ft_engine(stk_a, stk_b, data, 0);
}
