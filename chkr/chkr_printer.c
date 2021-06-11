/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:11 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:23:12 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	ft_chkr_verbose(t_stack *stk_a, t_stack *stk_b, t_stack *stk_s)
{
	int	i;

	i = 0;
	ft_printf("- - -\n");
	ft_printf("A\tB\tS\n");
	while (i < stk_a->size || i < stk_b->size || i < stk_s->size)
	{
		if (i < stk_a->size)
			ft_printf("%d", stk_a->arr[i]);
		else
			ft_printf(" ");
		if (i < stk_b->size)
			ft_printf("\t%d", stk_b->arr[i]);
		else
			ft_printf("\t");
		if (i < stk_s->size)
			ft_printf("\t%d", stk_s->arr[i]);
		i++;
		ft_printf("\n");
	}
	ft_printf("- - -\n");
}

void	ft_chkr_result(t_flg *flg)
{
	if (flg->result)
	{
		if (flg->verbose == 1)
			ft_printf("OK\n");
		if (flg->verbose == 2)
		{
			ft_printf("\n\e[32m\e[1mOK\e[0m\n");
			ft_printf("\nInstructions: %d\n\n", flg->instructions);
		}
	}
	else
	{
		if (flg->verbose == 1)
			ft_printf("KO\n");
		if (flg->verbose == 2)
			ft_printf("\e[31m\e[1mKO\e[0m\n");
	}
}
