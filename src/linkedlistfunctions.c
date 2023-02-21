/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/02/21 09:49:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*tmp;
	
	tmp = malloc(sizeof(t_node));
	if (!tmp)
		exit_error("Error");
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

	new = new_node(data);
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

/* int	get_median(t_node *head)
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
} */

int	get_median(t_node *head)
{
	t_node *tmp;
	int		median;
	int		*tab;
	int		len;

	if (head == NULL)
		return (0);
	tmp = node_copy(head);
	len = node_length(head);
	tab = get_sorted_tab(tmp);
	median = tab[len/2];
	free_nodes(&tmp);
	free(tab);
	return (median);
}

int	get_median2(t_node *head, int len)
{
	t_node *tmp;
	int	median;
	int	*tab;
	int	size;

	if (head == NULL)
		return (0);
	tmp = node_copy2(head, len);
	size = node_length(tmp);
	tab = get_sorted_tab(tmp);
	median = tab[size/2];
	free_nodes(&tmp);
	free(tab);
	return (median);
}

int	get_quarter(t_node *head, int quarters)
{
		t_node *tmp;
	int		quarter;
	int		*tab;
	int		len;

	if (head == NULL)
		return (0);
	tmp = node_copy(head);
	len = node_length(head);
	tab = get_sorted_tab(tmp);
	quarter = tab[len/4 * quarters];
	free_nodes(&tmp);
	free(tab);
	return (quarter);
}

int	get_portion(t_node *head, int part, int portion_nb)
{
		t_node *tmp;
	int		portion;
	int		*tab;
	int		len;

	if (head == NULL)
		return (0);
	tmp = node_copy(head);
	len = node_length(head);
	tab = get_sorted_tab(tmp);
	portion = tab[len/portion_nb * part];
	free_nodes(&tmp);
	free(tab);
	return (portion);
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
