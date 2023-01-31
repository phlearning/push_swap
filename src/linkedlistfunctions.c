/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/01/31 18:29:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_lastnode(t_node *head)
{
	t_node *lastnode;

	lastnode = head;
	if (lastnode == NULL)
		return (NULL);
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}

void	insert_beg(t_node **head_ref, int data)
{
	t_node	*new;

	new = my_malloc(sizeof(t_node));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = (*head_ref);
	*head_ref = new;
}

void	insert_end(t_node **head_ref, int data)
{
	t_node	*new;
	t_node	*lastnode;

	new = my_malloc(sizeof(t_node));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = NULL;
	if (*head_ref == NULL)
		*head_ref = new;
	else
	{
		lastnode = *head_ref;
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
		lastnode->next = new;
	}
}

void	pop(t_node **head_ref)
{
	t_node	*head;

	if (*head_ref == NULL)
		exit(EXIT_FAILURE);
	head = *head_ref;
	*head_ref = (*head_ref)->next;
	my_free(head);
}

int	peek(int pos, t_node *node)
{
	int	i;

	i = 0;
	while (i < pos-1 && node != NULL)
	{
		node = node->next;
		i++;
	}
	if (node != NULL)
		return (node->data);
	else
		return (-1);
}