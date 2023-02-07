#include "push_swap.h"
#include <stdio.h>

static void	init_cmds(t_stacks *stacks, t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = (int *)ft_calloc(sizeof(int), stacks->size_b);
	cmd->step_b = (int *)ft_calloc(sizeof(int), stacks->size_b);
	cmd->cmd_a = (char **)ft_calloc(sizeof(char *), stacks->size_b);
	cmd->cmd_b = (char **)ft_calloc(sizeof(char *), stacks->size_b);
	cmd->cmd_total = (int *)ft_calloc(sizeof(int), stacks->size_b);
	if (!(cmd->step_a && cmd->step_b && cmd->cmd_a && \
			cmd->cmd_b && cmd->cmd_total))
		exit(1);
}

static void	start_sorting(t_stacks *stacks, t_cmds *cmd)
{
	while (stacks->size_b)
	{
		init_cmds(stacks, cmd);
		get_cmds_a(stacks, cmd);
		get_cmds_b(stacks, cmd);
		get_cmds_total(stacks, cmd);
		find_min_commands(stacks, cmd);
		get_min_commands(cmd);
		execute_min_commands(stacks, cmd);
		do_pa(stacks, 1);
		free(cmd->step_a);
		free(cmd->step_b);
		free(cmd->cmd_a);
		free(cmd->cmd_b);
		free(cmd->cmd_total);
	}
}

void	sort_global(t_stacks *stacks, t_cmds *cmd)
{
	int	min;
	int	index_of_min;

	while (stacks->size_a > 5)
		do_pb(stacks, 1);
	ft_five_sort(stacks);
	start_sorting(stacks, cmd);
	min = find_min(stacks->stack_a);
	index_of_min = get_index(stacks->stack_a, min);
	while (stacks->stack_a->num != min)
	{
		if (index_of_min <= stacks->size_a / 2)
			do_ra(stacks, 1);
		else
			do_rra(stacks, 1);
	}
}
