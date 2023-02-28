/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 01:08:08 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	node_length(t_node *head)
{
	int		count;
	t_node	*tmp;

	count = 0;
	if (head == NULL)
		return (0);
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

t_node	*node_copy(t_node *stack, int len)
{
	t_node	*tmp;
	t_node	*stop;
	int		i;

	if (stack == NULL)
		return (NULL);
	if (stack != NULL)
		stop = stack;
	tmp = NULL;
	i = 0;
	while (stack != NULL && stack->next != stop && i < len)
	{
		insert_end(&tmp, stack->data);
		stack = stack->next;
	}
	if (stack->next == stop)
		insert_end(&tmp, stack->data);
	return (tmp);
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
