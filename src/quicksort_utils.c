/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:49:14 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:30:56 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_smaller_strict(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data < value)
			return (tmp->index);
		if (tmp->next->data < value)
			return (tmp->next->index);
		tmp = tmp->next;
	}
	return (0);
}

int	lastindex_smaller_strict(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp->next != node)
	{
		if (tmp->data < value)
			index = tmp->index;
		if (tmp->next->data < value)
			index = tmp->next->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_smaller_strict_than_a(t_stacks *stacks, int value)
{
	int	index;
	int	first_pos;
	int	second_pos;

	first_pos = index_smaller_strict(stacks->stack_a, value);
	second_pos = lastindex_smaller_strict(stacks->stack_a, value);
	if (compare_pos(first_pos, second_pos, stacks, "A"))
		index = first_pos;
	else
		index = second_pos;
	return (index);
}

void	rotate_smaller_strict_a(t_stacks *stacks, int value, int *count)
{
	int	smaller;
	int	half_size;

	if (stacks->stack_a->data >= value)
	{
		half_size = stacks->size_a / 2;
		smaller = index_smaller_strict_than_a(stacks, value);
		if (smaller <= half_size)
		{
			op_ra(stacks, stacks->flagprint);
			(*count)++;
		}
		else
		{
			op_rra(stacks, stacks->flagprint);
			(*count)--;
		}
	}
}

void	quick_sort_3(t_stacks *stacks)
{
	if (stacks->stack_a->data < stacks->stack_a->next->data && \
		stacks->stack_a->data < stacks->stack_a->next->next->data)
	{
		if (stacks->stack_a->next->data > stacks->stack_a->next->next->data)
		{
			op_rra(stacks, stacks->flagprint);
			op_sa(stacks, stacks->flagprint);
		}
	}
	else if (stacks->stack_a->data > stacks->stack_a->next->data && \
		stacks->stack_a->data > stacks->stack_a->next->next->data)
		qs3_strict_superior(stacks);
	else
	{
		if (stacks->stack_a->next->data < stacks->stack_a->next->next->data)
			op_sa(stacks, stacks->flagprint);
		else
			op_rra(stacks, stacks->flagprint);
	}
}
