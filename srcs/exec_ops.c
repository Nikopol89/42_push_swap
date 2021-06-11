/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:20:52 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:20:55 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_exec_a(t_data *data, t_stack *stk_a, int vr)
{
	while (data->ops->ra)
	{
		ft_rot(stk_a);
		data->ops->ra--;
		if (!vr)
			ft_printf("ra\n");
		data->total_ops++;
	}
	while (data->ops->rra)
	{
		ft_rev_rot(stk_a);
		data->ops->rra--;
		if (!vr)
			ft_printf("rra\n");
		data->total_ops++;
	}
}

static void	ft_exec_b(t_data *data, t_stack *stk_b, int vr)
{
	while (data->ops->rb)
	{
		ft_rot(stk_b);
		data->ops->rb--;
		if (!vr)
			ft_printf("rb\n");
		data->total_ops++;
	}
	while (data->ops->rrb)
	{
		ft_rev_rot(stk_b);
		data->ops->rrb--;
		if (!vr)
			ft_printf("rrb\n");
		data->total_ops++;
	}
}

static void	ft_exec_double(t_data *data, t_stack *stk_a, t_stack *stk_b, int vr)
{
	while (data->ops->rr)
	{
		ft_rot(stk_a);
		ft_rot(stk_b);
		data->ops->rr--;
		if (!vr)
			ft_printf("rr\n");
		data->total_ops++;
	}
	while (data->ops->rrr)
	{
		ft_rev_rot(stk_a);
		ft_rev_rot(stk_b);
		data->ops->rrr--;
		if (!vr)
			ft_printf("rrr\n");
		data->total_ops++;
	}
}

void	ft_exec_ops(t_data *data, t_stack *stk_a, t_stack *stk_b, int vr)
{
	ft_exec_a(data, stk_a, vr);
	ft_exec_b(data, stk_b, vr);
	ft_exec_double(data, stk_a, stk_b, vr);
}
