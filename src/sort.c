/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 16:15:07 by pvong            ###   ########.fr       */
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

t_node	*node_copy(t_node *stack)
{
	t_node	*tmp;
	t_node	*stop;

	if (stack == NULL)
		return (NULL);
	if (stack != NULL)
		stop = stack;
	tmp = NULL;
	while (stack != NULL && stack->next != stop)
	{
		insert_end(&tmp, stack->data);
		stack = stack->next;
	}
	if (stack->next == stop)
		insert_end(&tmp, stack->data);
	return (tmp);
}

t_node	*node_copy2(t_node *stack, int len)
{
	t_node	*tmp;
	t_node	*stop;
	int		i;

	if (stack == NULL)
		return (NULL);
	if (stack != NULL)
		stop = stack;
	tmp = NULL;
	i = 0;
	while (stack != NULL && stack->next != stop && i < len)
	{
		insert_end(&tmp, stack->data);
		stack = stack->next;
	}
	if (stack->next == stop)
		insert_end(&tmp, stack->data);
	return (tmp);
}

/* Sort a first time and put into the array sorted_tab.
Pass in the parameter a copy of the stack to not sort the main one. */
int	*get_sorted_tab(t_node *stack)
{
	int *tab;
	int	size;
	int	i;
	t_node	*tmp;
	
	if (stack == NULL)
		return (0);
	size = node_length(stack);
	tab = malloc(sizeof(int) * (size + 1));
	tmp = (stack);
	quicksort(tmp, tmp->prev);
	i = 0;
	while (i < size)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		++i;
	}
	tab[i] = '\0';
	return (tab);
}

void	sort(t_stacks *stacks)
{
	if (is_sorted(STACK_A))
		return ;
	if (stacks->size_a <= 3)
		sort_size_3(stacks);
	else if (stacks->size_a <= 5)
		sort_size_5(stacks);
	else
		sort_big_numbers(stacks);
}