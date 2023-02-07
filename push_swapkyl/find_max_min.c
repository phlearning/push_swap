#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->num;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num > max)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = stack->num;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num < min)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

int	get_index(t_stack *stack, int list)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->num == list)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
