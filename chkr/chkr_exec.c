/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:22:43 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:22:44 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	ft_chkr_exec_a(
	char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg)
{
	if (!(ft_memcmp(line, "pa", 3)))
	{
		ft_push(stk_b, stk_a);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "sa", 3)))
	{
		ft_swap(stk_a);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "ra", 3)))
	{
		ft_rot(stk_a);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "rra", 4)))
	{
		ft_rev_rot(stk_a);
		flg->instructions++;
	}
}

void	ft_chkr_exec_b(
	char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg)
{
	if (!(ft_memcmp(line, "pb", 3)))
	{
		ft_push(stk_a, stk_b);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "sb", 3)))
	{
		ft_swap(stk_b);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "rb", 3)))
	{
		ft_rot(stk_b);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "rrb", 4)))
	{	
		ft_rev_rot(stk_b);
		flg->instructions++;
	}
}

void	ft_chkr_exec_double(
	char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg)
{
	if (!(ft_memcmp(line, "rr", 3)))
	{
		ft_rot(stk_a);
		ft_rot(stk_b);
		flg->instructions++;
	}
	if (!(ft_memcmp(line, "rrr", 4)))
	{
		ft_rev_rot(stk_a);
		ft_rev_rot(stk_b);
		flg->instructions++;
	}
}
