/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:15 by pvong             #+#    #+#             */
/*   Updated: 2023/02/03 14:05:53 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/**
 * Take the first element in pile_src and push it to pile_dst
 * 
 * @param pile_dst 
 * @param pile_src 
 */
void	push(t_node **pile_src, t_node **pile_dst)
{
	if (*pile_src == NULL)
		return ;
	// ft_printf("inserting %d\n", (*pile_src)->data);
	insert_beg(*(&pile_dst), (*pile_src)->data);
	pop(*(&pile_src));
}

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

void	rrotate(t_node **head_ref)
{
	t_node	*current;
	t_node	*tmp;

	if (*head_ref == NULL)
		return ;
	tmp = *head_ref;
	while (tmp->next != NULL)
		tmp = tmp->next;
	current = *head_ref;
	tmp->next = *head_ref;
	*head_ref = current->next;
	current->next = NULL;
}