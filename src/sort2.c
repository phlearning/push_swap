/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:47:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s3_swap_rotate(t_stacks *stacks, int *len)
{
	if (*len == 3 && stacks->stack_a->data > stacks->stack_a->next->data \
		&& stacks->stack_a->next->next->data)
		op_sa(stacks, stacks->flagprint);
	else if (*len == 3 && !(stacks->stack_a->next->next->data > \
		stacks->stack_a->data && stacks->stack_a->next->next->data > \
		stacks->stack_a->next->data))
	{
		op_pb(stacks, stacks->flagprint);
		(*len)--;
	}
	else if (stacks->stack_a->data > stacks->stack_a->next->data)
		op_sa(stacks, stacks->flagprint);
	else if ((*len)++)
		op_pa(stacks, stacks->flagprint);
}

/**
 * 1. If the size of stack_a == 3 && given len == 3:
 * 		quick_sort_3 optimized sort for 3 numbers;
 * 2. Else if the len == 2:
 * 		check if 1rst element > 2nd element if yes swap
 * 3. Else if len == 3
 * 		check for the best placement and if the element of
 * 		stack: 1rst < 2nd < 3rd push
 * 		needed if for the first 3 elements;
 * @param stacks 
 * @param len 
 */
void	sort_3(t_stacks *stacks, int len)
{
	if (len == 3 && stacks->size_a == 3)
		quick_sort_3(stacks);
	else if (len == 2)
	{
		if (stacks->stack_a->data > stacks->stack_a->next->data)
			op_sa(stacks, stacks->flagprint);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stacks->stack_a->data < \
			stacks->stack_a->next->data \
			&& stacks->stack_a->next->data < stacks->stack_a->next->next->data))
			s3_swap_rotate(stacks, &len);
	}
}

void	ps3_swap_push(t_stacks *stacks, int *len)
{
	if (*len == 1 && stacks->stack_a->data > stacks->stack_a->next->data)
		op_sa(stacks, stacks->flagprint);
	else if (*len == 1 || (*len >= 2 && (stacks->stack_b->data > \
		stacks->stack_b->next->data)) || (*len == 3 && \
		stacks->stack_b->data > stacks->stack_b->next->next->data))
	{
		op_pa(stacks, stacks->flagprint);
		(*len)--;
	}
	else
		op_sb(stacks, stacks->flagprint);
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
		op_pa(stacks, stacks->flagprint);
	else if (len == 2)
	{
		if (stacks->stack_b->data < stacks->stack_b->next->data)
			op_sb(stacks, stacks->flagprint);
		op_pa(stacks, stacks->flagprint);
		op_pa(stacks, stacks->flagprint);
	}
	else if (len == 3)
	{
		while (len || !(stacks->stack_a->data < stacks->stack_a->next->data && \
			stacks->stack_a->next->data < stacks->stack_a->next->next->data))
			ps3_swap_push(stacks, &len);
	}
}

void	sort_big_numbers(t_stacks *stacks)
{
	int	nb1;
	int	nb2;

	if (!stacks->stack_a)
		return ;
	if (is_sorted(stacks->stack_a))
		return ;
	nb1 = compare_cmds(stacks, 0);
	nb2 = compare_cmds(stacks, 1);
	if (nb1 < nb2)
		quick_sort_a(stacks, stacks->size_a);
	else
		quick_sort_alta(stacks, stacks->size_a);
}
