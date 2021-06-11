#include "../push_swap.h"

void	ft_result(t_data *data, t_stack *stk)
{
	ft_printf("\n- - -\n\n");
	if (!(ft_memcmp(stk->arr, data->set, sizeof(*stk->arr) * stk->size)))
		ft_printf("\e[32m\e[1mPASS\e[0m\n");
	else
		ft_printf("\e[31m\e[1mFAIL\e[0m\n");
	ft_printf("\n%d MOVES\n", data->total_ops);
	ft_printf("\nprophecy %d\n", data->sub_size);
	ft_printf("\n- - -\n");
}

void	ft_print_stack(t_stack *stk_a, t_stack *stk_b, t_data *data)
{
	int	i;

	i = 0;
	ft_printf("- - -\n");
	ft_printf("A\tB\tS\n");
	while (i < stk_a->size || i < stk_b->size || i < data->set_size)
	{
		if (i < stk_a->size)
			ft_printf("%d", stk_a->arr[i]);
		else
			ft_printf(" ");
		if (i < stk_b->size)
			ft_printf("\t%d", stk_b->arr[i]);
		else
			ft_printf("\t");
		if (i < data->set_size)
			ft_printf("\t%d", data->set[i]);
		i++;
		ft_printf("\n");
	}
}

void	ft_print_subset(t_data *data)
{
	int	i;
	int	j;
	int	subset;

	i = 0;
	j = 0;
	subset = data->sub_pos;
	ft_printf("- - -\n");
	ft_printf("S_sz\t%d\n", data->set_size);
	ft_printf("sub_sz\t%d\n", data->sub_size);
	ft_printf("sub_cnt\t%d\n", data->sub_cnt);
	ft_printf("sub_pos\t%d\n", data->sub_pos);
	ft_printf("- - -\n");
	while (subset < data->sub_cnt)
	{
		ft_printf("subset\t%d\n", subset);
		while (i < data->sub_size && j < data->set_size)
		{
			ft_printf("%d\n", data->set[i + subset * data->sub_size]);
			i++;
			j++;
		}
		i = 0;
		subset++;
	}
	ft_printf("- - -\n");
}

void	ft_print_ops(t_data *data)
{
	ft_printf("ra\t%d\n", data->ops->ra);
	ft_printf("rra\t%d\n", data->ops->rra);
	ft_printf("rb\t%d\n", data->ops->rb);
	ft_printf("rrb\t%d\n", data->ops->rrb);
	ft_printf("rr\t%d\n", data->ops->rr);
	ft_printf("rrr\t%d\n", data->ops->rrr);
}