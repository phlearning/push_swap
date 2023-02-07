#include "./push_swap.h"

int	issorted(t_nums *nums)
{
	int	i;

	i = 0;
	while (i < nums->size - 1)
	{
		if (nums->numbers[i] > nums->numbers[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	issorted_list(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_error(void)
{
	write(0, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stacks *stacks)
{
	int		i;
	t_stack	*del;
	t_stack	*cur;

	i = 0;
	cur = stacks->stack_a;
	while (i < stacks->size_a)
	{
		del = cur;
		cur = cur->next;
		free(del);
		i++;
	}
}
