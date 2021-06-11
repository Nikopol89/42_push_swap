/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:28 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:29 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_clean_stks(t_stack *init, t_data *data,
	t_stack *stk_a, t_stack *stk_b)
{
	free(init->arr);
	free(stk_a->arr);
	free(stk_b->arr);
	free(data->set);
}

static void	ft_clean_args(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->ac)
	{
		free(args->av[i]);
		i++;
	}
	free(args->av);
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_stack		init;
	t_stack		stk_a;
	t_stack		stk_b;
	t_data		data;

	if (!(ft_init_args(argc, argv, &args)))
		return (0);
	if (!(ft_error_check(&args)))
		return (0);
	if (!(ft_init_stk(&args, &init, &stk_a, &stk_b)))
		return (0);
	if (!(ft_init_set(&data, &init)))
		return (0);
	if (!(ft_error_check_dupl(&data)))
		return (0);
	ft_re_init(&init, &stk_a, &stk_b, &data);
	if (ft_memcmp(stk_a.arr, data.set, sizeof(*stk_a.arr) * stk_a.size))
		ft_prophet(&init, &stk_a, &stk_b, &data);
	ft_clean_stks(&init, &data, &stk_a, &stk_b);
	ft_clean_args(&args);
	return (0);
}
