/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:24 by pvong             #+#    #+#             */
/*   Updated: 2023/01/31 16:28:49 by pvong            ###   ########.fr       */
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
int	check_inputs(int ac, char **av, t_node **pile_a)
{
	int		i;

	i = -1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (0);
		check_and_split(pile_a, av);
	}
	if (ac > 2)
	{
		while (++i < ac)
		{
			if (av[i][0] == '\0')
				return (0);
		}
		check_all_args(pile_a, av);
	}
	return (0);
}