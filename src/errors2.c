/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:02:13 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 18:03:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check_and_split: split the first argument, check and exit if there are
 * errors in the argument, if not insert the numbers and returns; \v
 * 1. Split into multiple string;
 * 2. Check the strings
 * 3. Check for duplicate numbers
 * 4. Check for double signs
 * 5. Convert into int and returns
 * 
 * @param pile_a 
 * @param pile_b 
 * @param ac 
 * @param av 
 * @return int 
 */
int	check_and_split(t_node **stack_a, char **av)
{
	char	**tmp;

	tmp = ft_split(av[1], ' ');
	if (check_error(tmp) == -1)
	{
		free_split(tmp);
		exit_error("Error");
	}
	insert_all(stack_a, tmp);
	free_split(tmp);
	return (0);
}

void	exit_error(char *str)
{
	ft_putendl_fd(str, ERROR_FD);
	exit(1);
}
