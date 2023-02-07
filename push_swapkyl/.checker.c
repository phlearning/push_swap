#include "push_swap.h"

void	ft_do_cmds(t_stacks *stacks, char *line)
{
	if (!ft_strncmp(line, "sa", 100))
		do_sa(stacks, 0);
	else if (!ft_strncmp(line, "sb", 100))
		do_sb(stacks, 0);
	else if (!ft_strncmp(line, "ss", 100))
		do_ss(stacks, 0);
	else if (!ft_strncmp(line, "pa", 100))
		do_pa(stacks, 0);
	else if (!ft_strncmp(line, "pb", 100))
		do_pb(stacks, 0);
	else if (!ft_strncmp(line, "ra", 100))
		do_ra(stacks, 0);
	else if (!ft_strncmp(line, "rb", 100))
		do_rb(stacks, 0);
	else if (!ft_strncmp(line, "rr", 100))
		do_rr(stacks, 0);
	else if (!ft_strncmp(line, "rra", 100))
		do_rra(stacks, 0);
	else if (!ft_strncmp(line, "rrb", 100))
		do_rrb(stacks, 0);
	else if (!ft_strncmp(line, "rrr", 100))
		do_rrr(stacks, 0);
	else
		ft_error();
}

void	ft_read_cmds(t_stacks *stacks)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_do_cmds(stacks, line);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_nums		nums;
	t_stacks	stacks;

	if (argc == 1)
		exit(1);
	init_nums(&nums);
	init_stacks(&stacks);
	ft_parse(argc, argv, &nums);
	check_duplicates(&nums);
	save_to_list(&stacks, &nums);
	ft_read_cmds(&stacks);
	if (!issorted_list(stacks.stack_a) && !stacks.size_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stacks);
	return (0);
}
