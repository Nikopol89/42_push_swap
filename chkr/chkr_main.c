/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:01 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:23:02 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static void	ft_chkr_compare(t_stack *stk_a, t_stack *stk_s, t_flg *flg)
{
	if (!(ft_memcmp(stk_a->arr, stk_s->arr, sizeof(*stk_s->arr) * stk_s->size)))
		flg->result = 1;
	else
		flg->result = 0;
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_stack	stk_a;
	t_stack	stk_b;
	t_stack	stk_s;
	t_flg	flg;

	if (argc < 2)
		return (0);
	ft_chkr_flags(argv, &flg);
	if (!(ft_chkr_init_args(argc, argv, &args, &flg)))
		return (0);
	if (!(ft_error_check(&args)))
		return (0);
	if ((!ft_chkr_init(&args, &stk_a, &stk_b, &stk_s)))
		return (0);
	if (!(ft_chkr_dupl(&stk_s)))
		return (0);
	if (!(ft_chkr_read(&stk_a, &stk_b, &stk_s, &flg)))
		return (0);
	ft_chkr_compare(&stk_a, &stk_s, &flg);
	ft_chkr_result(&flg);
	ft_chkr_clean(&args, &stk_a, &stk_b, &stk_s);
	return (0);
}
