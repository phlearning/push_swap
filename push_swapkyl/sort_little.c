#include "./push_swap.h"

void	ft_small_sort(t_stacks *stacks)
{
	int	max;

	max = find_max(stacks->stack_a);
	if (stacks->size_a == 1)
		return ;
	else if (stacks->size_a == 2)
	{
		if (stacks->stack_a->num > stacks->stack_a->next->num)
			do_sa(stacks, 1);
	}
	else if (stacks->size_a == 3)
	{
		if (stacks->stack_a->num == max)
			do_ra(stacks, 1);
		if (stacks->stack_a->next->num == max)
			do_rra(stacks, 1);
		if (stacks->stack_a->num > stacks->stack_a->next->num)
			do_sa(stacks, 1);
	}
}

void	ft_five_sort(t_stacks *stacks)
{
	int	i;
	int	min;
	int	max;

	i = stacks->size_b;
	min = find_min(stacks->stack_a);
	max = find_max(stacks->stack_a);
	while (stacks->size_b - i != 2)
	{
		if (stacks->stack_a->num == min || stacks->stack_a->num == max)
			do_pb(stacks, 1);
		else
			do_ra(stacks, 1);
	}
	ft_small_sort(stacks);
	do_pa(stacks, 1);
	do_pa(stacks, 1);
	if (stacks->stack_a->num == max)
		do_ra(stacks, 1);
	else
	{
		do_sa(stacks, 1);
		do_ra(stacks, 1);
	}
}
