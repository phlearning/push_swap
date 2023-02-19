/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/19 16:17:47 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_min_a(t_stacks *stacks)
{
	int	mid;
	int	min;
	int	index_min;

	min = get_min(STACK_A);	
	while (DATA_A != min)
	{
		min = get_min(STACK_A);
		mid = SIZE_A / 2;
		index_min = get_index(STACK_A, min);
		if (index_min <= mid)
			op_ra(stacks);
		else
			op_rra(stacks);
	}
}

int	is_sorted(t_node *head)
{
	t_node *tmp;
	int		size;
	int		i;

	tmp = head;
	size = node_length(head);
	i = 0;
	while (i < size -1)
	{
		if (tmp->data > tmp->next->data)
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
	t_node	*stop;

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

int	get_first_pivot(t_node *stack)
{
	int	middle;
	t_node	*tmp;

	tmp = node_copy(stack);
	quicksort(tmp, get_lastnode(tmp));
	middle = get_median(tmp);
	free_nodes(&tmp);
	return (middle);
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
	quicksort(tmp, get_lastnode(tmp));
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