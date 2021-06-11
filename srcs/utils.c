/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:21:53 by jmartini          #+#    #+#             */
/*   Updated: 2021/06/11 15:21:55 by jmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memint(const int *s, int c, int size)
{
	const int	*ptr;

	ptr = s;
	while (size--)
	{
		if (*ptr == c)
			return ((int *)ptr);
		ptr++;
	}
	return (0);
}

static void	ft_clean_heap(char ***tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

static int	ft_init_sub_cnt(char ***tmp)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (tmp[i])
	{
		while (tmp[i][j])
		{
			j++;
			cnt++;
		}
		j = 0;
		i++;
	}
	return (cnt);
}

int	ft_init_cpycnt(t_args *args, char ***tmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	args->av = ft_calloc(ft_init_sub_cnt(tmp), sizeof(*args->av));
	if (!args->av)
		return (0);
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k])
		{
			args->av[j] = tmp[i][k];
			j++;
			k++;
		}
		i++;
	}
	ft_clean_heap(tmp);
	return (j);
}
