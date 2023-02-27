/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:18:31 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * sort_size_3: sort the stack_a if the size is less than 3.
 * 1-2-3 // 1-3-2 // 2-1-3 // 2-3-1 // 3-1-2 // 3-2-1
 * sort 1 
 * @param stacks 
 */
void	sort_size_3(t_stacks *stacks)
{
	int	max;

	if (stacks->size_a == 1)
		return ;
	if (stacks->size_a == 2)
	{
		if (stacks->stack_a->data > stacks->stack_a->next->data)
			op_ra(stacks);
		return ;
	}
	if (stacks->size_a == 3)
	{
		max = get_max(STACK_A);
		if (stacks->stack_a->data == max)
			op_ra(stacks);
		if (stacks->stack_a->next->data == max)
			op_rra(stacks);
		if (stacks->stack_a->data > stacks->stack_a->next->data)
			op_sa(stacks);
	}
}

void	quick_sort_3(t_stacks *stacks)
{
	if (DATA_A1 < DATA_A2 && DATA_A1 < DATA_A3)
	{
		if (DATA_A2 > DATA_A3)
		{
			op_rra(stacks);
			op_sa(stacks);
		}
	}
	else if (DATA_A1 > DATA_A2 && DATA_A1 > DATA_A3)
	{
		if (DATA_A2 < DATA_A3)
			op_ra(stacks);
		else
		{
			op_sa(stacks);
			op_rra(stacks);
		}
	}
	else
	{
		if (DATA_A2 < DATA_A3)
			op_sa(stacks);
		else
			op_rra(stacks);
	}
}

/**
 * 1. If the size of stack_a == 3 && given len == 3:
 * 		quick_sort_3 optimized sort for 3 numbers;
 * 2. Else if the len == 2:
 * 		check if 1rst element > 2nd element if yes swap
 * 3. Else if len == 3
 * 		check for the best placement and if the element of
 * 		stack_b: 1rst < 2nd < 3rd push
 * 		needed if for the first 3 elements;
 * @param stacks 
 * @param len 
 */
void	sort_3(t_stacks *stacks, int len)
{
	// if (len == 3 && SIZE_A == 3)
	// 	quick_sort_3(stacks);
	if (len == 2)
	{
		if (DATA_A1 > DATA_A2)
			op_sa(stacks);
	}
	else if (len == 3)
	{
		while (len != 3 || !(DATA_A1 < DATA_A2 \
			&& DATA_A2 < DATA_A3))
		{
			if (len == 3 && DATA_A1 > DATA_A2 && DATA_A3)
				op_sa(stacks);
			else if (len == 3 && !(DATA_A3 > DATA_A1 \
				&& DATA_A3 > DATA_A2))
			{
				op_pb(stacks);
				len--;
			}
			else if (DATA_A1 > DATA_A2)
				op_sa(stacks);
			else if (len++)
				op_pa(stacks);	
		}
	}
}

/**
 * If the pushed element to b is 1, push it back
 * If there are 2 elements pushed to b, check which one is biggest
 * and push both back;
 * If there are 3 elements pushed to b, check for optimal disposition
 * in A and check that the biggest of 3 is pushed
 * @param stacks 
 * @param len 
 */
void	push_sort_3_b_to_a(t_stacks *stacks, int len)
{
	if (len == 1)
		op_pa(stacks);
	else if (len == 2)
	{
		if (DATA_B1 < DATA_B2)
			op_sb(stacks);
		op_pa(stacks);
		op_pa(stacks);
	}
	else if (len == 3)
	{
		while (len || !(DATA_A1 < DATA_A2 && DATA_A2 < DATA_A3))
		{
			if (len == 1 && DATA_A1 > DATA_A2)
				op_sa(stacks);
			else if (len == 1 || (len >= 2 && (DATA_B1 > DATA_B2)) \
				|| (len == 3 && DATA_B1 > DATA_B3))
			{
				op_pa(stacks);
				len--;
			}
			else
				op_sb(stacks);
		}
	}
}

void	sort_size_5(t_stacks *stacks)
{
	int	min;
	int	max;

	min = get_min(STACK_A);
	max = get_max(STACK_A);
	while (SIZE_B != 2)
	{
		if (DATA_A == min || DATA_A == max)
			op_pb(stacks);
		else
			op_ra(stacks);
	}
	sort_size_3(stacks);
	op_pa(stacks);
	op_pa(stacks);
	if (DATA_A == max)
		op_ra(stacks);
	else
	{
		op_sa(stacks);
		op_ra(stacks);
	}
}

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

void	sort_big_numbers(t_stacks *stacks)
{
	if (!STACK_A)
		return ;
	if (is_sorted(STACK_A))
		return ;
	quick_sort_a(stacks, SIZE_A);
}