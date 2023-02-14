/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:01 by pvong             #+#    #+#             */
/*   Updated: 2023/02/13 15:26:28 by pvong            ###   ########.fr       */
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
	int	i;
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
	int	i;
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

/* Put the index to the stack_a and stack_b */
void	index_reput(t_stacks *stacks)
{
	put_index_stack_a(stacks);
	put_index_stack_b(stacks);
}

void	change_index(t_stacks *stacks, char *cmds)
{
	if (!ft_strncmp(cmds, "sa", 10))
		index_sa(stacks);
	if (!ft_strncmp(cmds, "sb", 10))
		index_sb(stacks);
	if (!ft_strncmp(cmds, "ss", 10))
		index_ss(stacks);
	if (!ft_strncmp(cmds, "ra", 10))
		put_index_stack_a(stacks);
	if (!ft_strncmp(cmds, "rb", 10))
		put_index_stack_b(stacks);
	if (!ft_strncmp(cmds, "rr", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "rra", 10))
		put_index_stack_a(stacks);
	if (!ft_strncmp(cmds, "rrb", 10))
		put_index_stack_b(stacks);
	if (!ft_strncmp(cmds, "rrr", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "pa", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "pb", 10))
		index_reput(stacks);
}

/**
 * get_index: look for the index based on the data
 * @param head 
 * @param num 
 * @return int 
 */
int	get_index(t_node *head, int num)
{
	t_node	*tmp;

	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == num)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

int	get_lastindex(t_node *head, int num)
{
	t_node	*tmp;
	int		index;

	if (head == NULL)
		return (0);
	tmp = head;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->data == num)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

/**
 * get_data_by_index: look for the data on the stack by index
 * @param head 
 * @param index 
 * @return int 
 */
int	get_data_by_index(t_node *head, int index)
{
	t_node *tmp;

	if (head == NULL)
		return (0);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->index == index)
			return (tmp->data);
		tmp = tmp->next;
	}
	return (0);
}