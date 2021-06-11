/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chkr_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:23:18 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:23:19 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static void	ft_chkr_exec(char *line, t_stack *stk_a, t_stack *stk_b, t_flg *flg)
{
	ft_chkr_exec_a(line, stk_a, stk_b, flg);
	ft_chkr_exec_b(line, stk_a, stk_b, flg);
	ft_chkr_exec_double(line, stk_a, stk_b, flg);
}

static int	ft_chkr_validity(t_stack *stk_a, t_stack *stk_s, int ret)
{
	if (ret > 0 && !(ft_memcmp(stk_a->arr, stk_s->arr,
				sizeof(*stk_s->arr) * stk_s->size)))
		return (0);
	return (1);
}

static void	ft_chkr_read_sup(
	char *line, t_stack *stk_a, t_stack *stk_b, t_stack *stk_s)
{
	ft_printf("%s\n", line);
	ft_chkr_verbose(stk_a, stk_b, stk_s);
}

int	ft_chkr_read(t_stack *stk_a, t_stack *stk_b, t_stack *stk_s, t_flg *flg)
{
	char	*line;
	int		ret;
	int		check;

	ret = 1;
	if (flg->verbose == 2)
		ft_chkr_verbose(stk_a, stk_b, stk_s);
	check = ft_chkr_validity(stk_a, stk_s, ret);
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (!check && ret > 0)
		{
			ft_printf("KO\n");
			free(line);
			return (0);
		}
		ft_chkr_exec(line, stk_a, stk_b, flg);
		if (flg->verbose == 2 && ret > 0)
			ft_chkr_read_sup(line, stk_a, stk_b, stk_s);
		free(line);
	}
	return (1);
}
