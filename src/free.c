/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/02/15 00:46:20 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_nodes(t_node *head_ref)
{
	t_node	*tmp;

	while (head_ref != NULL)
	{
		tmp = head_ref;
		head_ref = head_ref->next;
		free(tmp);
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (STACK_A)
		free_nodes(stacks->stack_a);
	if (STACK_B)
		free_nodes(stacks->stack_b);
	if (SORTED_TAB)
		free(SORTED_TAB);
	if (stacks)
		free(stacks);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
