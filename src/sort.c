/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/03 17:50:09 by pvong            ###   ########.fr       */
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

int	get_pivot(t_node *stack)
{
	int	middle;
	t_node	*tmp;

	tmp = node_copy(stack);
	quicksort(tmp, get_lastnode(tmp));
	middle = get_median(tmp);
	free_stack(tmp);
	return (middle);
}

t_node	*sort(t_node **stack)
{
	t_node	*lt;
	t_node	*ge;
	t_node	*node;
	t_node	*next;

	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		return (*stack);
		node = (*stack)->next;
	lt = NULL;
	ge = NULL;
	while (node)
	{
		next = node->next;
		if (node->data < (*stack)->data)
		{
			node->next = lt;
			lt = node;
		}
		else
		{
			node->next = ge;
			ge = node;
		}
		node = next;
	}
	ft_printf("\n----pile_a----\n");
		printlist(*stack);
	t_node	*ltail = sort(&lt);
	t_node	*gtail = sort(&ge);

	(*stack)->next = ge;

	if (gtail == NULL)
		gtail = *stack;
	if (lt)
	{
		ltail->next = *stack;
		*stack = lt;
	}
	return (gtail);
}