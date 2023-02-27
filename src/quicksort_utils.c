/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:49:14 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:50:06 by pvong            ###   ########.fr       */
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

	first_pos = index_smaller_strict(STACK_A, value);
	second_pos = lastindex_smaller_strict(STACK_A, value);
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

	if (DATA_A >= value)
	{
		half_size = SIZE_A /2;
		smaller = index_smaller_strict_than_a(stacks, value);
		if (smaller <= half_size)
		{
			op_ra(stacks);
			(*count)++;
		}
		else
		{
			op_rra(stacks);
			(*count)--;
		}
	}
}