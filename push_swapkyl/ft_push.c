#include "push_swap.h"

void	do_pa(t_stacks *stacks, int flag)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!stacks->size_b)
		return ;
	tmp = stacks->stack_b;
	stacks->size_a++;
	new = new_list(stacks->stack_b->num, stacks->stack_b->index);
	if (!new)
		exit(1);
	list_add_front(&stacks->stack_a, new);
	stacks->stack_b = stacks->stack_b->next;
	free(tmp);
	stacks->size_b--;
	if (flag)
		write(1, "pa\n", 3);
}

void	do_pb(t_stacks *stacks, int flag)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!stacks->size_a)
		return ;
	tmp = stacks->stack_a;
	stacks->size_b++;
	new = new_list(stacks->stack_a->num, stacks->stack_a->index);
	if (!new)
		exit(1);
	list_add_front(&stacks->stack_b, new);
	stacks->stack_a = stacks->stack_a->next;
	free(tmp);
	stacks->size_a--;
	if (flag)
		write(1, "pb\n", 3);
}
