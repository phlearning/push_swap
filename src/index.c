/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:01 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:38:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * put_index_stack_a: Add the index to the stack_a.
 * We go to the top of the stack_a and add one by one the index;
 * @param stacks 
 */
void	put_index_stack_a(t_stacks *stacks)
{
	int		i;
	t_node	*tmp;

	if (STACK_A == NULL)
		return ;
	i = 0;
	tmp = STACK_A;
	while (i < stacks->size_a)
	{
		STACK_A->index = i;
		STACK_A = STACK_A_NEXT;
		i++;
	}
	STACK_A = tmp;
}

/* Add index to the stack_b */
void	put_index_stack_b(t_stacks *stacks)
{
	int		i;
	t_node	*tmp;

	if (STACK_B == NULL)
		return ;
	i = 0;
	tmp = STACK_B;
	while (i < SIZE_B)
	{
		STACK_B->index = i;
		STACK_B = STACK_B_NEXT;
		i++;
	}
	STACK_B = tmp;
}

/**
 * Index_sa: change the index of the swapped nodes in stack_a.
 * The movement has already been made so we need to get to the
 * second nodes.
 * @param stacks 
 */
void	index_sa(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = STACK_A_NEXT;
	STACK_A_NEXT->index = STACK_A->index;
	STACK_A->index = tmp->index;
}

/**
 * Index_sb: change the index of the swapped nodes in stack_b.
 * The movement has already been made so we need to get to the
 * second nodes.
 * @param stacks 
 */
void	index_sb(t_stacks *stacks)
{
	t_node	*tmp;

	tmp = STACK_B_NEXT;
	STACK_B_NEXT->index = STACK_B->index;
	STACK_B->index = tmp->index;
}

/* Index_sa & Index_sb */
void	index_ss(t_stacks *stacks)
{
	index_sa(stacks);
	index_sb(stacks);
}
