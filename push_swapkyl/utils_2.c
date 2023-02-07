#include "push_swap.h"

void	init_nums(t_nums *nums)
{
	nums->numbers = 0;
	nums->size = 0;
}

void	init_cmd(t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = 0;
	cmd->step_b = 0;
	cmd->cmd_total = 0;
	cmd->cmd_a = NULL;
	cmd->cmd_b = NULL;
}

void	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
}

void	check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (!str[i])
		ft_error();
	while (str[i])
		if (!ft_isdigit(str[i++]))
			ft_error();
}

void	check_duplicates(t_nums *nums)
{
	int	i;
	int	j;

	i = 0;
	while (++i < nums->size)
	{
		j = -1;
		while (++j < i)
			if (nums->numbers[j] == nums->numbers[i])
				ft_error();
	}
}
