/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:02:30 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_nodes(t_node **head)
{
	t_node	*next;
	t_node	*tmp;

	if (head && *head)
	{
		next = (*head)->next;
		while (next && (next != *head))
		{
			tmp = next;
			next = next->next;
			free(tmp);
		}
		free(*head);
		*head = NULL;
	}
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	if (stacks->stack_a)
		free_nodes(&stacks->stack_a);
	if (stacks->stack_b)
		free_nodes(&stacks->stack_b);
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
