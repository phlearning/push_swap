#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_nums		nums;
	t_cmds		cmd;
	t_stacks	stacks;

	if (argc == 1)
		exit(1);
	init_nums(&nums);
	init_cmd(&cmd);
	init_stacks(&stacks);
	ft_parse(argc, argv, &nums);
	check_duplicates(&nums);
	if (issorted(&nums))
	{
		save_to_list(&stacks, &nums);
		if (stacks.size_a <= 3)
			ft_small_sort(&stacks);
		else if (stacks.size_a <= 5)
			ft_five_sort(&stacks);
		else
			sort_global(&stacks, &cmd);
	}
	free_stack(&stacks);
	return (0);
}
