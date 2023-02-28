/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:51:37 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 00:32:44 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_bigger_equal(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data >= value)
			return (tmp->index);
		if (tmp->next->data >= value)
			return (tmp->next->index);
		tmp = tmp->next;
	}
	return (0);
}

int	lastindex_bigger_equal(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp->next != node)
	{
		if (tmp->data >= value)
			index = tmp->index;
		if (tmp->next->data >= value)
			index = tmp->next->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_bigger_equal_b(t_stacks *stacks, int value)
{
	int	index;
	int	first_pos;
	int	second_pos;

	first_pos = index_bigger_equal(STACK_B, value);
	second_pos = lastindex_bigger_equal(STACK_B, value);
	if (compare_pos(first_pos, second_pos, stacks, "B"))
		index = first_pos;
	else
		index = second_pos;
	return (index);
}

void	rotate_bigger_equal_b(t_stacks *stacks, int value, int *count)
{
	int	smaller;
	int	half_size;

	if (DATA_B < value)
	{
		half_size = SIZE_B / 2 + SIZE_B % 2;
		smaller = index_bigger_equal_b(stacks, value);
		if (smaller <= half_size)
		{
			op_rb(stacks);
			(*count)++;
		}
		else
		{
			op_rrb(stacks);
			(*count)--;
		}
	}
}
