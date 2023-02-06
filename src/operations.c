/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:15 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 17:53:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap the first two elements in pile */
void	swap(t_node **head_ref)
{
	t_node	*current;
	t_node	*index;
	int		tmp;

	if (head_ref == NULL || *head_ref == NULL)
		return ;
	else
	{
		current = *head_ref;
		if (*head_ref != NULL && (*head_ref)->next == NULL)
			return ;
		tmp = current->data;
		index = current->next;
		current->data = index->data;
		index->data = tmp;
	}
}

/**
 * Take the first element in pile_src and push it to pile_dst
 * 
 * @param pile_dst 
 * @param pile_src 
 */
void	push(t_node **stack_src, t_node **stack_dst)
{
	if (*stack_src == NULL)
		return ;
	// ft_printf("inserting %d\n", (*pile_src)->data);
	insert_beg(*(&stack_dst), (*stack_src)->data);
	pop(*(&stack_src));
}

/* void	push(t_node **stack_src, t_node **stack_dst)
{
	if (*stack_src == NULL)
		return ;
	insert_beg(*(&stack_dst), (*stack_src)->data);
	pop(*(&stack_src));
} */


/**
 * Rotate: Rotate towards the top, firstnode to the last spot.
 * Moving each element next to the first to one sport before.
 * @param head_ref 
 */
void	rotate(t_node **head_ref)
{
	t_node	*current;
	t_node	*index;

	current = *head_ref;
	if (current == NULL)
		return ;
	index = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = index->next;
	index->next = NULL;
}

/**
 * Reverse Rotate: rotate towards the bottom, lastnode to the top.
 * Moving each node to the next.
 * Linking the first element to the top (which corresponds to
 * the rotate element).
 * @param head 
 */
void rrotate(t_node **head)
{
	t_node	*lastnode_to_top;
	t_node	*current;
	int		len;

	if (!*head)
		return ;
	lastnode_to_top = get_lastnode(*head);
	len = node_length(*head) - 1;
	current = *head;
	while (len - 1 > 0 && current != NULL)
	{
		current = current->next;
		len--;
	}
	lastnode_to_top->next = *head;
	*head = current->next;
	current->next = NULL;
}