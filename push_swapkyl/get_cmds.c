#include "push_swap.h"

static void	ft_if_max(t_stacks *stacks, t_cmds *cmd, int max, int i)
{
	int	index;

	index = get_index(stacks->stack_a, max);
	if (index < stacks->size_a / 2)
	{
		cmd->step_a[i] = index + 1;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->size_a - index - 1;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_if_min(t_stacks *stacks, t_cmds *cmd, int min, int i)
{
	int	index;

	index = get_index(stacks->stack_a, min);
	if (index <= stacks->size_a / 2)
	{
		cmd->step_a[i] = index;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->size_a - index;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_if_between(t_stacks *stacks, t_cmds *cmd, int i, t_stack
*tmp_b)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = stacks->stack_a;
	while (j < stacks->size_a - 1)
	{
		if (tmp_b->num > tmp->num && tmp_b->num < tmp->next->num)
		{
			if (j < stacks->size_a / 2)
			{
				cmd->step_a[i] = j + 1;
				cmd->cmd_a[i] = "ra";
			}
			else
			{
				cmd->step_a[i] = stacks->size_a - (j + 1);
				cmd->cmd_a[i] = "rra";
			}
			j = stacks->size_a;
		}
		tmp = tmp->next;
		j++;
	}
}

void	get_cmds_a(t_stacks *stacks, t_cmds *cmd)
{
	int		i;
	int		min;
	int		max;
	t_stack	*tmp_b;

	tmp_b = stacks->stack_b;
	i = -1;
	while (++i < stacks->size_b)
	{
		max = find_max(stacks->stack_a);
		min = find_min(stacks->stack_a);
		if (tmp_b->num > max)
			ft_if_max(stacks, cmd, max, i);
		else if (tmp_b->num < min)
			ft_if_min(stacks, cmd, min, i);
		else
			ft_if_between(stacks, cmd, i, tmp_b);
		if (cmd->step_a[i] == 0)
			cmd->cmd_a[i] = NULL;
		tmp_b = tmp_b->next;
	}
}

void	get_cmds_b(t_stacks *stacks, t_cmds *cmd)
{
	int	i;

	i = 0;
	while (++i < stacks->size_b)
	{
		if (i <= stacks->size_b / 2)
		{
			cmd->step_b[i] = i;
			cmd->cmd_b[i] = "rb";
		}
		else
		{
			cmd->step_b[i] = stacks->size_b - i;
			cmd->cmd_b[i] = "rrb";
		}
	}
	if (stacks->size_b % 2 == 0)
		if (!ft_strncmp(cmd->cmd_a[stacks->size_b / 2], "rra", 100))
			cmd->cmd_b[stacks->size_b / 2] = "rrb";
}
