#include "push_swap.h"

void	do_sa(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a->next;
	stacks->stack_a->next = stacks->stack_a->next->next;
	tmp->next = stacks->stack_a;
	stacks->stack_a = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	do_sb(t_stacks *stacks, int flag)
{
	t_stack	*tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b->next;
	stacks->stack_b->next = stacks->stack_b->next->next;
	tmp->next = stacks->stack_b;
	stacks->stack_b = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	do_ss(t_stacks *stacks, int flag)
{
	do_sa(stacks, 0);
	do_sb(stacks, 0);
	if (flag)
		write(1, "ss\n", 3);
}
