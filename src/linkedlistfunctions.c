/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:55 by pvong             #+#    #+#             */
/*   Updated: 2023/01/26 16:14:07 by pvong            ###   ########.fr       */
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

/* Swap the first two elements in pile */
void	swap(t_node **head_ref)
{
	t_node	*current;
	t_node	*index;
	int		tmp;

	if (head_ref == NULL)
		return ;
	else
	{
		current = *head_ref;
		tmp = current->data;
		index = current->next;
		current->data = index->data;
		index->data = tmp;
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

/* Take the first element in pile_src and push it to pile_dst */
void	push(t_node **pile_dst, t_node **pile_src)
{
		if (*pile_src == NULL)
		return ;
	ft_printf("inserting %d\t", (*pile_src)->data);
	insert_beg(*(&pile_dst), (*pile_src)->data);
	pop(*(&pile_src));
}