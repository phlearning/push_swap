/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 08:29:23 by pvong            ###   ########.fr       */
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
			op_ra(stacks, FLAG);
		return ;
	}
	if (stacks->size_a == 3)
	{
		max = get_max(STACK_A);
		if (stacks->stack_a->data == max)
			op_ra(stacks, FLAG);
		if (stacks->stack_a->next->data == max)
			op_rra(stacks, FLAG);
		if (stacks->stack_a->data > stacks->stack_a->next->data)
			op_sa(stacks, FLAG);
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
	if (len == 3 && SIZE_A == 3)
		quick_sort_3(stacks);
	else if (len == 2)
	{
		if (DATA_A1 > DATA_A2)
			op_sa(stacks, FLAG);
	}
	else if (len == 3)
	{
		while (len != 3 || !(DATA_A1 < DATA_A2 && DATA_A2 < DATA_A3))
		{
			if (len == 3 && DATA_A1 > DATA_A2 && DATA_A3)
				op_sa(stacks, FLAG);
			else if (len == 3 && !(DATA_A3 > DATA_A1 \
				&& DATA_A3 > DATA_A2))
			{
				op_pb(stacks, FLAG);
				len--;
			}
			else if (DATA_A1 > DATA_A2)
				op_sa(stacks, FLAG);
			else if (len++)
				op_pa(stacks, FLAG);
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
		op_pa(stacks, FLAG);
	else if (len == 2)
	{
		if (DATA_B1 < DATA_B2)
			op_sb(stacks, FLAG);
		op_pa(stacks, FLAG);
		op_pa(stacks, FLAG);
	}
	else if (len == 3)
	{
		while (len || !(DATA_A1 < DATA_A2 && DATA_A2 < DATA_A3))
		{
			if (len == 1 && DATA_A1 > DATA_A2)
				op_sa(stacks, FLAG);
			else if (len == 1 || (len >= 2 && (DATA_B1 > DATA_B2)) \
				|| (len == 3 && DATA_B1 > DATA_B3))
			{
				op_pa(stacks, FLAG);
				len--;
			}
			else
				op_sb(stacks, FLAG);
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
			op_pb(stacks, FLAG);
		else
			op_ra(stacks, FLAG);
	}
	sort_size_3(stacks);
	op_pa(stacks, FLAG);
	op_pa(stacks, FLAG);
	if (DATA_A == max)
		op_ra(stacks, FLAG);
	else
	{
		op_sa(stacks, FLAG);
		op_ra(stacks, FLAG);
	}
}

void	sort_big_numbers(t_stacks *stacks)
{
	int	nb1;
	int	nb2;

	if (!STACK_A)
		return ;
	if (is_sorted(STACK_A))
		return ;
	nb1 = compare_cmds(stacks, 0);
	nb2 = compare_cmds(stacks, 1);
	if (nb1 < nb2)
		quick_sort_a(stacks, SIZE_A);
	else
		quick_sort_alta(stacks, SIZE_A);
}
