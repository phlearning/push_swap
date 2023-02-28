/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:01 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:04:24 by pvong            ###   ########.fr       */
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

	if (stacks->stack_a == NULL)
		return ;
	i = 0;
	tmp = stacks->stack_a;
	while (i < stacks->size_a)
	{
		stacks->stack_a->index = i;
		stacks->stack_a = stacks->stack_a->next;
		i++;
	}
	stacks->stack_a = tmp;
}

/* Add index to the stack_b */
void	put_index_stack_b(t_stacks *stacks)
{
	int		i;
	t_node	*tmp;

	if (stacks->stack_b == NULL)
		return ;
	i = 0;
	tmp = stacks->stack_b;
	while (i < stacks->size_b)
	{
		stacks->stack_b->index = i;
		stacks->stack_b = stacks->stack_b->next;
		i++;
	}
	stacks->stack_b = tmp;
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

	tmp = stacks->stack_a->next;
	stacks->stack_a->next->index = stacks->stack_a->index;
	stacks->stack_a->index = tmp->index;
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

	tmp = stacks->stack_b->next;
	stacks->stack_b->next->index = stacks->stack_b->index;
	stacks->stack_b->index = tmp->index;
}

/* Index_sa & Index_sb */
void	index_ss(t_stacks *stacks)
{
	index_sa(stacks);
	index_sb(stacks);
}
