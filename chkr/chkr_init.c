/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:22:49 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:22:52 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

void	ft_chkr_flags(char **argv, t_flg *flg)
{
	flg->verbose = 1;
	if (!(ft_memcmp(argv[1], "-v", 3)))
		flg->verbose = 2;
	flg->instructions = 0;
}

int	ft_chkr_dupl(t_stack *stk_s)
{
	int	i;

	i = 0;
	while (i < stk_s->size - 1)
	{
		if (stk_s->arr[i] == stk_s->arr[i + 1])
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_chkr_init_args(int argc, char **argv, t_args *args, t_flg *flg)
{
	int		i;
	int		j;
	char	***tmp;

	i = flg->verbose;
	j = 0;
	if (argc < 2)
		return (0);
	tmp = ft_calloc(argc, sizeof(*tmp));
	if (!tmp)
		return (0);
	while (i < argc)
	{
		tmp[i - flg->verbose] = ft_split(argv[i], ' ');
		i++;
	}
	args->ac = ft_init_cpycnt(args, tmp);
	if (!args->ac)
		return (0);
	return (1);
}

int	ft_chkr_init(t_args *args, t_stack *stk_a, t_stack *stk_b, t_stack *stk_s)
{
	int	i;

	i = 0;
	stk_a->arr = ft_calloc(args->ac + 1, sizeof(*stk_a->arr));
	stk_b->arr = ft_calloc(args->ac + 1, sizeof(*stk_b->arr));
	if (!stk_a->arr || !stk_b->arr)
		return (0);
	stk_a->size = args->ac;
	stk_b->size = 0;
	stk_s->size = stk_a->size;
	while (i < stk_a->size)
	{
		stk_a->arr[i] = ft_atoi(args->av[i]);
		i++;
	}
	stk_s->arr = ft_ins_sort(stk_a->arr, stk_s->size);
	if (!stk_s->arr)
		return (0);
	return (1);
}

void	ft_chkr_clean(
	t_args *args, t_stack *stk_a, t_stack *stk_b, t_stack *stk_s)
{
	int	i;

	i = 0;
	while (i < args->ac)
	{
		free(args->av[i]);
		i++;
	}
	free(args->av);
	free(stk_a->arr);
	free(stk_b->arr);
	free(stk_s->arr);
}
