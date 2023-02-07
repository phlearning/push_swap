#include "./push_swap.h"

void	save_to_list(t_stacks *stacks, t_nums *nums)
{
	int		i;
	t_stack	*list;

	i = 0;
	while (i < nums->size)
	{
		list = new_list(nums->numbers[i], -1);
		if (!list)
			exit(1);
		list_add_back(&stacks->stack_a, list);
		stacks->size_a++;
		i++;
	}
	free(nums->numbers);
}
