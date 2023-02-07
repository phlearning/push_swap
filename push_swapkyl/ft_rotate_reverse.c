#include "./push_swap.h"

void	do_rra(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = stacks->stack_a;
	stacks->stack_a = tmp->next;
	tmp->next = NULL;
	if (flag)
		write(1, "rra\n", 4);
}

void	do_rrb(t_stacks *stacks, int flag)
{
	int		i;
	t_stack	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b;
	i = 0;
	while (i < stacks->size_b - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next->next = stacks->stack_b;
	stacks->stack_b = tmp->next;
	tmp->next = NULL;
	if (flag)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stacks *stacks, int flag)
{
	do_rra(stacks, 0);
	do_rrb(stacks, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
