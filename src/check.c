/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:24 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:04:41 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	input_param(t_stacks *stacks)
{
	stacks->size_a = node_length(stacks->stack_a);
	stacks->size_b = 0;
	stacks->size_start = stacks->size_a;
	put_index_stack_a(stacks);
}

int	check_all_args(t_node **stack_a, char **av)
{
	if (check_error(av + 1) == -1)
		exit_error("Error");
	insert_all(stack_a, av + 1);
	return (0);
}

/**
 * Check: Check for errors before putting in the list
 * @param ac 
 * @param av 
 * @param pile_a 
 * @return * int 
 */
int	check_inputs_and_insert(int ac, char **av, t_stacks *stacks)
{
	int		i;

	i = -1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (0);
		check_and_split(&stacks->stack_a, av);
		if (stacks->stack_a == NULL)
			return (0);
	}
	if (ac > 2)
	{
		while (++i < ac)
		{
			if (av[i][0] == '\0')
				return (0);
		}
		check_all_args(&stacks->stack_a, av);
	}
	input_param(stacks);
	return (0);
}
