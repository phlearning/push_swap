/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:24 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 17:00:48 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check: Check for errors before putting in the list
 * @param ac 
 * @param av 
 * @param pile_a 
 * @return * int 
 */
int	check_inputs(int ac, char **av, t_stacks *stacks)
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
	stacks->size_a = node_length(stacks->stack_a);
	stacks->size_b = 0;
	return (0);
}
