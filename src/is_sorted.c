/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:22 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:27:01 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_len_sorted(t_node *head, int len)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (i < len - 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	is_sorted(t_node *head)
{
	t_node	*tmp;
	int		size;
	int		i;

	tmp = head;
	size = node_length(head);
	i = 0;
	while (i < size - 1)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	is_len_rev_sorted(t_node *head, int len)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (i < len - 1)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	is_rev_sorted(t_node *head)
{
	t_node	*tmp;
	int		size;
	int		i;

	tmp = head;
	size = node_length(head);
	i = 0;
	while (i < size - 1)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
