/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:40 by pvong             #+#    #+#             */
/*   Updated: 2023/02/23 13:26:52 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Push_swap: With different operations (swap, push, rotate)(a/b/r) 
 * sort the pile_a. Show the different operations to sort the pile_a.
 * Can use 2 piles (a or b) to sort.
 * 
 * TODO: 1. Check inputs for errors
 * TODO: 2.	Insert inputs
 * TODO: 3. Sort and show operations
 * TODO: 4.	Free
 * @param ac 
 * @param av 
 * @return int 
 */

int	main(int ac, char **av)
{
	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		free(stacks);
		exit(1);
	}
	init_stacks(stacks);
	check_inputs_and_insert(ac, av, stacks);
	if (SIZE_A == 0)
	{
		free_stacks(stacks);
		return (0);
	}
	// printlist2(stacks);

	sort(stacks);
	// printlist2(stacks);
	// ft_printf("CHUNKS: %d \n", NB_CHUNKS);
	// ft_printf("\nNb cmds: %d\n", stacks->cmds.nb_cmds);
	printcmds(stacks);
	free_stacks(stacks);

	return (0);
}
