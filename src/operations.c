/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:15 by pvong             #+#    #+#             */
/*   Updated: 2023/01/18 17:27:53 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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