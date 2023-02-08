/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/08 15:15:27 by pvong            ###   ########.fr       */
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
	int	i;
	i = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
		{
			pivot = first;
			tmp = first->data;
			first->data = front->data;
			front->data = tmp;

			first = first->next;
			i++;
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

t_node	*node_copy(t_node *stack)
{
	t_node	*tmp;

	tmp = NULL;
	while (stack != NULL)
	{
		insert_end(&tmp, stack->data);
		stack = stack->next;
	}
	return (tmp);
}

int	get_first_pivot(t_node *stack)
{
	int	middle;
	t_node	*tmp;

	tmp = node_copy(stack);
	quicksort(tmp, get_lastnode(tmp));
	middle = get_median(tmp);
	free_nodes(tmp);
	return (middle);
}

void	sort(t_stacks *stacks)
{
	if (stacks->size_a <= 3)
		sort_size_3(stacks);
	else if (stacks->size_a <= 5)
		sort_size_5(stacks);
	else
		sort_big_numbers(stacks);
}