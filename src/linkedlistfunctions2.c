/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistfunctions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:31:19 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:41:44 by pvong            ###   ########.fr       */
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
