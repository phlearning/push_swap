/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/09 17:17:35 by pvong            ###   ########.fr       */
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
		max = stacks->max;
		if (stacks->stack_a->data == max)
			op_ra(stacks);
		else if (stacks->stack_a->next->data == max)
			op_rra(stacks);
		if (stacks->stack_a->data > stacks->stack_a->next->data)
			op_sa(stacks);
	}
}

void	sort_size_5(t_stacks *stacks)
{
	while (SIZE_B != 2)
	{
		if (DATA_A == STACKS_MIN || DATA_A == STACKS_MAX)
			op_pb(stacks);
		else
			op_ra(stacks);
	}
	sort_size_3(stacks);
	op_pa(stacks);
	op_pa(stacks);
	if (DATA_A > DATA_A_NEXT)
		op_ra(stacks);
	else
	{
		op_sa(stacks);
		op_ra(stacks);
	}
}

/* void	sort_big_numbers(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (STACK_A != NULL)
	{
		if (DATA_A != STACKS_MIN)
		{
			if (INDEX_MIN < SIZE_A/2)
				op_ra(stacks);
			else
				op_rra(stacks);
		}
		if (DATA_A == STACKS_MIN)
		{
			op_pb(stacks);
			STACKS_MIN = get_min(STACK_A);
			INDEX_MIN = get_index(STACK_A, STACKS_MIN);
		}
	}
	while (STACK_B != NULL)
		op_pa(stacks);
} */

int	compare_pos(int min_pos, int max_pos, t_stacks *stacks)
{
	int	distance_min;
	int	distance_max;
	int	half_size;

	half_size = SIZE_A / 2;

	if (min_pos > half_size)
		distance_min = SIZE_A - min_pos;
	else
		distance_min = min_pos;
	if (max_pos > half_size)
		distance_max = SIZE_A - max_pos;
	else
		distance_max = max_pos;
	if (distance_min <= distance_max && min_pos <= half_size)
		return (1);
	else if (distance_max <= distance_min && max_pos <= half_size)
		return (1);
	else if (distance_min <= distance_max && min_pos > half_size)
		return (0);
	else if (distance_max <= distance_min && max_pos > half_size)
		return (0);
	return (0);
}

void	sort_big_numbers(t_stacks *stacks)
{
	int	count;
	int	i;
	int	delimitation;
	int	delimit_index;

	count = 1;
	while (STACK_A != NULL && count < NB_CHUNKS - 1)
	{
	ft_printf("test1\n");
		i = 0;
		delimitation = SORTED_TAB[ONE_CHUNK * count + i];
		delimit_index = get_index(STACK_A, delimitation);
		while (SIZE_A >= STACK_SIZE - ONE_CHUNK)
		{
			ft_printf("test2\n");
			if (DATA_A == STACKS_MIN)
			{
				op_pb(stacks);
				if (SIZE_B > 1)
				{
					op_rrb(stacks);
					if (DATA_B < DATA_B_NEXT)
					{
						op_sb(stacks);
					}
					op_rb(stacks);
					op_rb(stacks);
				}
				STACKS_MIN = get_min(STACK_A);
				INDEX_MIN = get_index(STACK_A, STACKS_MIN);
			}
			ft_printf("test3\n");
			if (DATA_B == delimitation)
			{
				op_pb(stacks);
				i--;
				delimitation = SORTED_TAB[ONE_CHUNK * count + i];
				delimit_index = get_index(STACK_A, delimitation);
			}
			ft_printf("test4\n");
			if (compare_pos(INDEX_MIN, delimit_index, stacks))
				op_ra(stacks);
			else
				op_rra(stacks);
		}
		++count;
	}
	while (STACK_A != NULL)
	{
		STACKS_MIN = get_min(STACK_A);
		if (DATA_A == STACKS_MIN)
		{
			op_pb(stacks);
			op_rb(stacks);
		}
		else
			op_ra(stacks);
	}
}