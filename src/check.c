/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:24 by pvong             #+#    #+#             */
/*   Updated: 2023/02/22 14:01:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	input_param(t_stacks *stacks)
{
	t_node	*tmp;

	SIZE_A = node_length(STACK_A);
	SIZE_B = 0;
	STACK_SIZE = SIZE_A;
	stacks->min = get_min(STACK_A);
	stacks->max = get_max(STACK_A);
	put_index_stack_a(stacks);
	TAIL_A = get_lastnode(STACK_A);
	TAIL_A->next = STACK_A;
	STACK_A->prev = TAIL_A;
	NB_CHUNKS = get_chunks(stacks);
	tmp = node_copy(STACK_A);
	SORTED_TAB = get_sorted_tab(tmp);
	free_nodes(&tmp);
	if (NB_CHUNKS > 0)
		ONE_CHUNK = (int) (STACK_SIZE / NB_CHUNKS);
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
		if (STACK_A == NULL)
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
