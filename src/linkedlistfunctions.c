/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/02/19 16:09:50 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*tmp;
	tmp = malloc(sizeof(t_node));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_node	*get_lastnode(t_node *head)
{
	t_node *lastnode;

	lastnode = head;
	if (lastnode == NULL)
		return (NULL);
	while (lastnode->next != head)
		lastnode = lastnode->next;
	return (lastnode);
}

void	insert_beg(t_node **head_ref, int data)
{
	insert_end(head_ref, data);
	if (!(head_ref && *head_ref))
		return ;
	*head_ref = (*head_ref)->prev;
}

void	insert_end(t_node **head_ref, int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(-1);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	if (*head_ref)
	{
		(*head_ref)->prev->next = new;
		new->prev = (*head_ref)->prev;
		new->next = *head_ref;
		(*head_ref)->prev = new;
	}
	else
	{
		*head_ref = new;
		new->prev = new;
		new->next = new;
	}
}

/* void	pop(t_node **head_ref)
{
	t_node	*head;

	if (*head_ref == NULL)
		return ;
	head = *head_ref;
	if (head->next == head)
	{
		*head_ref = NULL;
		return ;
	}
	else
	{
		*head_ref = (*head_ref)->next;
		free(head);
		head = NULL;
		return ;
	}
} */

/**
 * Connect the link between the nodes before freeing
 * 
 * @param head_ref 
 */
void	pop(t_node **head_ref)
{
	t_node	*node;

	if (!(head_ref && *head_ref))
        return ;
	node = *head_ref;
    node->next->prev = node->prev;
    node->prev->next = node->next;
	if (node != node->next)
		*head_ref = node->next;
	else
		*head_ref = NULL;
    free(node);
    return ;
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
	t_node	*tmp;

	count = 0;
	tmp = head;
	if (head)
		++count;
	while (tmp->next != head)
	{
		tmp = tmp->next;
		count++;
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
/* Look for the lowest number in the stack */
int	get_min(t_node *node)
{
	int		min;
	t_node	*tmp;

	if (node == NULL)
		return (0);
	tmp = node;
	min = tmp->data;
	while (tmp->next != node)
	{
		if (tmp->data < min)
			min = tmp->data;
		if (tmp->next->data < min)
			min = tmp->next->data;
		tmp = tmp->next;
	}
	return (min);
}

/* Look for the highest number in the stack */
int	get_max(t_node *node)
{
	int		max;
	t_node	*tmp;

	if (node == NULL)
		return (0);
	tmp = node;
	max = tmp->data;
	while (tmp->next != node)
	{
		if (tmp->data > max)
			max = tmp->data;
		if (tmp->next->data > max)
			max = tmp->next->data;
		tmp = tmp->next;
	}
	return (max);
}
