#include "./push_swap.h"

void	do_ra(t_stacks *stacks, int flag)
{
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (stacks->size_a < 2)
		return ;
	tmp_1 = stacks->stack_a;
	while (tmp_1->next)
		tmp_1 = tmp_1->next;
	tmp_2 = stacks->stack_a->next;
	stacks->stack_a->next = NULL;
	tmp_1->next = stacks->stack_a;
	stacks->stack_a = tmp_2;
	if (flag)
		write(1, "ra\n", 3);
}

void	do_rb(t_stacks *stacks, int flag)
{
	int		i;
	t_stack	*tmp_1;
	t_stack	*tmp_2;

	if (stacks->size_b < 2)
		return ;
	tmp_1 = stacks->stack_b;
	i = 0;
	while (i < stacks->size_b - 1)
	{
		tmp_1 = tmp_1->next;
		i++;
	}
	tmp_2 = stacks->stack_b->next;
	stacks->stack_b->next = NULL;
	tmp_1->next = stacks->stack_b;
	stacks->stack_b = tmp_2;
	if (flag)
		write(1, "rb\n", 3);
}

void	do_rr(t_stacks *stacks, int flag)
{
	do_ra(stacks, 0);
	do_rb(stacks, 0);
	if (flag)
		write(1, "rr\n", 3);
}
