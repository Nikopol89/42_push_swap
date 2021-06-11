/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:16 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:17 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_init_args(int argc, char **argv, t_args *args)
{
	int		i;
	int		j;
	char	***tmp;

	i = 1;
	j = 0;
	if (argc < 2)
		return (0);
	tmp = ft_calloc(argc, sizeof(*tmp));
	if (!tmp)
		return (0);
	while (i < argc)
	{
		tmp[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	args->ac = ft_init_cpycnt(args, tmp);
	if (!args->ac)
		return (0);
	return (1);
}

int	ft_init_stk(t_args *args, t_stack *init, t_stack *stk_a, t_stack *stk_b)
{
	int	i;

	i = 0;
	if (args->ac < 2)
		return (0);
	init->arr = ft_calloc(args->ac + 1, sizeof(*init->arr));
	stk_a->arr = ft_calloc(args->ac + 1, sizeof(*stk_a->arr));
	stk_b->arr = ft_calloc(args->ac + 1, sizeof(*stk_b->arr));
	if (!init->arr || !stk_a->arr || !stk_b->arr)
		return (0);
	init->size = args->ac;
	while (i < init->size)
	{
		init->arr[i] = ft_atoi(args->av[i]);
		i++;
	}
	return (1);
}

int	ft_init_set(t_data *data, t_stack *init)
{
	data->set_size = init->size;
	data->set = ft_ins_sort(init->arr, data->set_size);
	if (!data->set)
		return (0);
	data->sub_pos = 0;
	data->total_ops = 0;
	data->sub_size = 10;
	return (1);
}

void	ft_re_init(t_stack *init, t_stack *stk_a, t_stack *stk_b, t_data *data)
{
	float	i;

	stk_a->size = init->size;
	stk_b->size = 0;
	ft_memcpy(stk_a->arr, init->arr, sizeof(*stk_a->arr) * stk_a->size);
	data->sub_pos = 0;
	data->total_ops = 0;
	i = (float)data->set_size / data->sub_size;
	if (i > (int)i)
		data->sub_cnt = i + 1;
	else
		data->sub_cnt = i;
}

void	ft_init_ops(t_data *data)
{
	data->ops->ra = 0;
	data->ops->rra = 0;
	data->ops->rb = 0;
	data->ops->rrb = 0;
	data->ops->rr = 0;
	data->ops->rrr = 0;
}
