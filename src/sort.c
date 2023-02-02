/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/02 19:02:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*partition(t_node *first, t_node *last)
{
	t_node	*pivot;
	t_node	*front;
	int		tmp;

	pivot = first;
	front = first;
	tmp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
		{
			pivot = first;
			tmp = first->data;
			first->data = front->data;
			front->data = tmp;

			first = first->next;
		}
		front = front->next;
	}
	tmp = first->data;
	first->data = last->data;
	last->data = tmp;
	return (pivot);
}

void	quicksort(t_node *first, t_node *last)
{
	t_node	*pivot;

	if (first == last)
		return ;
	pivot = partition(first, last);
	if (pivot != NULL && pivot->next != NULL)
		quicksort(pivot->next, last);
	if (pivot != NULL && first != pivot)
		quicksort(first, pivot);
}