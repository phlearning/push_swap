#include "push_swap.h"

void	list_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

t_stack	*list_last(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		return (stack);
	}
	return (NULL);
}

void	list_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = list_last(*stack);
	if (last)
		last->next = new;
	else
		*stack = new;
}

t_stack	*new_list(int number, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = number;
	new->index = index;
	new->next = NULL;
	return (new);
}
