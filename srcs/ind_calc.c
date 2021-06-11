/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ind_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:00 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:01 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_step1(t_data *data, t_stack *stk_a, t_stack *stk_b, int vr)
{
	if (ft_ind_is_next(stk_a, data))
	{
		ft_swap(stk_a);
		if (!vr)
			ft_printf("sa\n");
		data->total_ops++;
	}
	if (ft_ind_is_minor(stk_a, stk_a->arr[0]) && !ft_ind_is_ordered(stk_a)
		&& !ft_ind_is_next(stk_a, data))
	{
		ft_push(stk_a, stk_b);
		if (!vr)
			ft_printf("pb\n");
		data->total_ops++;
	}
}

static void	ft_step2(t_data *data, t_stack *stk_a, int vr)
{
	int	tmp_size;

	if (stk_a->size % 2)
		tmp_size = stk_a->size + 1;
	else
		tmp_size = stk_a->size;
	if ((ft_ind_find_minor(stk_a) + 1) > ((tmp_size / 2))
		&& !ft_ind_is_ordered(stk_a) && !ft_ind_is_next(stk_a, data)
		&& !ft_ind_is_minor(stk_a, stk_a->arr[0]))
	{
		ft_rev_rot(stk_a);
		if (!vr)
			ft_printf("rra\n");
		data->total_ops++;
	}
	else if (!ft_ind_is_ordered(stk_a) && !ft_ind_is_next(stk_a, data)
		&& !ft_ind_is_minor(stk_a, stk_a->arr[0]))
	{
		ft_rot(stk_a);
		if (!vr)
			ft_printf("ra\n");
		data->total_ops++;
	}
}

void	ft_ind_calc(t_stack *stk_a, t_stack *stk_b, t_data *data, int vr)
{
	while (!(ft_ind_is_ordered(stk_a)))
	{
		ft_step1(data, stk_a, stk_b, vr);
		ft_step2(data, stk_a, vr);
	}
	while (stk_b->size)
	{
		ft_push(stk_b, stk_a);
		if (!vr)
			ft_printf("pa\n");
		data->total_ops++;
	}
}
