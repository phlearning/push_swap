/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:39:43 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 08:19:42 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Compare_pos: compare the pos of 2 value.
 * Calculate the distance of the first and second value relative to top/bottom.
 * If first value's distance is smaller
 * return (1);
 * If second value's distance is smaller
 * returns (0);
 */
int	compare_pos(int first_pos, int sec_pos, t_stacks *stacks, char *a_or_b)
{
	int	distance_first;
	int	distance_sec;
	int	half_size;
	int	size;

	if (!ft_strncmp(a_or_b, "A", 2))
		size = SIZE_A;
	else
		size = SIZE_B;
	half_size = size / 2;
	if (first_pos > half_size)
		distance_first = size - first_pos;
	else
		distance_first = first_pos;
	if (sec_pos > half_size)
		distance_sec = size - sec_pos;
	else
		distance_sec = sec_pos;
	if (distance_first < distance_sec)
		return (1);
	else
		return (0);
	return (-1);
}

/**
 * Compare_stack_to_value: Check if there are still numbers
 * inferior to the value given in the stack.
 * @param node 
 * @param value 
 * @return int 
 */
int	compare_stack_to_value(t_node *node, int value)
{
	t_node	*tmp;

	if (node == NULL)
		return (0);
	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data <= value)
			return (1);
		if (tmp->next->data <= value)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->data <= value)
		return (1);
	return (0);
}


int	compare_cmds(t_stacks *stacks, int flag_quicksort)
{
	t_stacks	*tmpstacks;
	int			nb_op;

	tmpstacks = malloc(sizeof(t_stacks));
	if (!stacks)
	{
		free(tmpstacks);
		free_stacks(stacks);
		exit(1);
	}
	init_stacks(tmpstacks, 0);
	tmpstacks->stack_a = node_copy(STACK_A, SIZE_A);
	input_param(tmpstacks);
	if (flag_quicksort == 1)
		quick_sort_alta(tmpstacks, SIZE_A);
	else
		quick_sort_a(tmpstacks, SIZE_A);
	nb_op = tmpstacks->cmds.nb_cmds;
	free_stacks(tmpstacks);
	return (nb_op);
}