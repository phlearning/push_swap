/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/02/03 15:46:17 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*tmp;
	tmp = malloc(sizeof(t_node));
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

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

int	pop(t_node **head_ref)
{
	t_node	*head;
	int		popped;

	if (*head_ref == NULL)
		exit(EXIT_FAILURE);
	head = *head_ref;
	*head_ref = (*head_ref)->next;
	popped = head->data;
	my_free(head);
	return (popped);
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

/* void	org_push(t_node **pile, int data)
{
	t_node	*tmp;

	tmp = new_node(data);
	tmp->next = *pile;
	*pile = tmp;
} */

int	node_length(t_node *head)
{
	int		count;
	t_node	*node;

	count = 0;
	node = head;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	get_median(t_node *head)
{
	int		len;
	int		mid;
	int		i;
	t_node	*node;

	len = node_length(head);
	node = head;
	i = 0;
	mid = len/2;
	while (i < mid)
	{
		node = node->next;
		i++;
	}
	if (len % 2 == 0)
		return ((node->data + node->next->data) / 2);
	else
		return (node->data);
}