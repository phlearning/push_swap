/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:56:12 by pvong             #+#    #+#             */
/*   Updated: 2023/02/19 15:21:36 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_nodes(t_node **head) 
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


/* void	free_nodes(t_node *head_ref)
{
	t_node	*tmp;

	while (head_ref != NULL)
	{
		tmp = head_ref;
		if (head_ref->next)
			head_ref = head_ref->next;
		free(tmp);
	}
	free(head_ref);
	head_ref = NULL;
} */

void	free_stacks(t_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	if (STACK_A)
		free_nodes(&STACK_A);
	if (STACK_B)
		free_nodes(&STACK_B);
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
