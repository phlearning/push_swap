#include "./push_swap.h"

void	get_cmds_total(t_stacks *stacks, t_cmds *cmd)
{
	int	i;

	cmd->cmd_total[0] = cmd->step_a[0];
	i = 1;
	while (i < stacks->size_b)
	{
		if ((!ft_strncmp(cmd->cmd_a[i], "ra", 100) && \
			!ft_strncmp(cmd->cmd_b[i], "rb", 100)) || \
			(!ft_strncmp(cmd->cmd_a[i], "rra", 100) && \
			 !ft_strncmp(cmd->cmd_b[i], "rrb", 100)))
		{
			if (cmd->step_a[i] > cmd->step_b[i])
				cmd->cmd_total[i] = cmd->step_a[i];
			else
				cmd->cmd_total[i] = cmd->step_b[i];
		}
		else if ((!ft_strncmp(cmd->cmd_a[i], "ra", 100) && \
				!ft_strncmp(cmd->cmd_b[i], "rrb", 100)) || \
				(!ft_strncmp(cmd->cmd_a[i], "rra", 100) && \
				 !ft_strncmp(cmd->cmd_b[i], "rb", 100)))
			cmd->cmd_total[i] = cmd->step_a[i] + cmd->step_b[i];
		else if (!cmd->cmd_a[i])
			cmd->cmd_total[i] = cmd->step_b[i];
		i++;
	}
}

void	find_min_commands(t_stacks *stacks, t_cmds *cmd)
{
	int	i;
	int	cmd_min;

	cmd_min = cmd->cmd_total[0];
	cmd->index = 0;
	i = 1;
	while (i < stacks->size_b)
	{
		if (cmd->cmd_total[i] < cmd_min)
		{
			cmd_min = cmd->cmd_total[i];
			cmd->index = i;
		}
		i++;
	}
}

void	get_min_commands(t_cmds *cmd)
{
	if ((!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100) && \
			!ft_strncmp(cmd->cmd_b[cmd->index], "rb", 100)) || \
			(!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100) && \
			 !ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 100)))
	{
		if (cmd->step_a[cmd->index] > cmd->step_b[cmd->index])
		{
			cmd->do_a = cmd->step_a[cmd->index] - cmd->step_b[cmd->index];
			cmd->do_ab = cmd->step_b[cmd->index];
		}
		else
		{
			cmd->do_b = cmd->step_b[cmd->index] - cmd->step_a[cmd->index];
			cmd->do_ab = cmd->step_a[cmd->index];
		}
	}
	else
	{
		cmd->do_a = cmd->step_a[cmd->index];
		cmd->do_b = cmd->step_b[cmd->index];
	}
}

void	execute_min_commands(t_stacks *stacks, t_cmds *cmd)
{
	while (cmd->do_a)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100))
			do_ra(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100))
			do_rra(stacks, 1);
		cmd->do_a--;
	}
	while (cmd->do_b)
	{
		if (!ft_strncmp(cmd->cmd_b[cmd->index], "rb", 100))
			do_rb(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 100))
			do_rrb(stacks, 1);
		cmd->do_b--;
	}
	while (cmd->do_ab)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100))
			do_rr(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100))
			do_rrr(stacks, 1);
		cmd->do_ab--;
	}
}
