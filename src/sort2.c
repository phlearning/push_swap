/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/07 17:25:07 by pvong            ###   ########.fr       */
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
		if (stacks->stack_a->next->data == max)
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

void	sort_big_numbers(t_stacks *stacks)
{
	int	min;

	min = STACKS_MIN;
	while (STACK_A != NULL)
	{
		if (DATA_A == min)
		{
			op_pb(stacks);
			min = get_min(STACK_A);
		}
		else
			op_ra(stacks);
	}
	while (STACK_B != NULL)
		op_pa(stacks);
}