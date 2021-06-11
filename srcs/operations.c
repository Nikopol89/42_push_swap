/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:34 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:36 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack *src, t_stack *dst)
{
	if (src->size)
	{
		ft_memmove(&dst->arr[1], &dst->arr[0],
			sizeof(*dst->arr) * dst->size);
		dst->arr[0] = src->arr[0];
		dst->size++;
		ft_memmove(&src->arr[0], &src->arr[1],
			sizeof(*src->arr) * src->size);
		src->size--;
	}
}

void	ft_swap(t_stack *stk)
{
	int		tmp;

	tmp = stk->arr[0];
	stk->arr[0] = stk->arr[1];
	stk->arr[1] = tmp;
}

void	ft_rot(t_stack *stk)
{
	int		tmp;

	tmp = stk->arr[0];
	ft_memmove(&stk->arr[0], &stk->arr[1],
		sizeof(*stk->arr) * stk->size);
	stk->arr[stk->size - 1] = tmp;
}

void	ft_rev_rot(t_stack *stk)
{
	int		tmp;

	tmp = stk->arr[stk->size - 1];
	ft_memmove(&stk->arr[1], &stk->arr[0],
		sizeof(*stk->arr) * stk->size);
	stk->arr[0] = tmp;
}
