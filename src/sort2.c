/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/15 18:48:43 by pvong            ###   ########.fr       */
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

/*
 * Compare_pos: compare the pos of 2 value.
 * Calculate the distance of the first and second value relative to top/bottom.
 * If first value's distance is smaller
 * return (1);
 * If second value's distance is smaller
 * returns (0);
 */
int	compare_pos(int first_pos, int sec_pos, t_stacks *stacks)
{
	int	distance_first;
	int	distance_sec;
	int	half_size;

	half_size = SIZE_A / 2;

	if (first_pos > half_size)
		distance_first = SIZE_A - first_pos;
	else
		distance_first = first_pos;
	if (sec_pos > half_size)
		distance_sec = SIZE_A - sec_pos;
	else
		distance_sec = sec_pos;
	if (distance_first <= distance_sec)
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

	tmp = node;
	while (tmp)
	{
		if (tmp->data <= value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	lastindex_by_comparaison(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp)
	{
		if (tmp->data <= value)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_by_comparaison(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp)
	{
		if (tmp->data <= value)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}


/* The index corresponds to the index of the number smaller than the value.
It should be either the closest to the top or bottom */
int	index_smaller_than(t_stacks *stacks, int value)
{
	int	index;
	int	first_pos;
	int	second_pos;

	first_pos = index_by_comparaison(STACK_A, value);
	second_pos = lastindex_by_comparaison(STACK_A, value);
	if (compare_pos(first_pos, second_pos, stacks))
		index = first_pos;
	else
		index = second_pos;
/* 	ft_printf("value[%d]: %d ||", first_pos, get_data_by_index(STACK_A, first_pos));
	ft_printf("value[%d]: %d\t", second_pos, get_data_by_index(STACK_A, second_pos));
	ft_printf("index[%d]: %d\n", index, get_data_by_index(STACK_A, index)); */
	return (index);
}

/* Get a smaller number to the top of the stack */
void	smart_chunk_rotate(t_stacks *stacks, int value)
{
	int	smaller;
	int	half_size;

	while (DATA_A > value)
	{
		smaller = index_smaller_than(stacks, value);
		half_size = SIZE_A / 2;
		if (smaller < half_size)
			op_ra(stacks);
		else
			op_rra(stacks);	
	}
}

/**
 * Push_chunk: Push the top of stack_a if smaller than the value
 * else get the next value according to the chunks limit.
 * @param stacks 
 * @param size 
 * @param increment 
 */
void	push_chunk(t_stacks *stacks, int value, int i)
{
	while (compare_stack_to_value(STACK_A, value))
	{
		// ft_printf("----pivot [%d]: %d----\n", i, value);
		if (DATA_A <= value)
		{
			op_pb(stacks);
			if (STACK_B_NEXT && DATA_B_NEXT > DATA_B)
				op_sb(stacks);
		}	
		if (!(compare_stack_to_value(STACK_A, value)))
		{
			// ft_printf("prev_value: %d ||", value);
			value = chunk_limit(stacks, ++i);
			// ft_printf("next_value: %d\n", value);
			// sleep(2);
		}	
		else
			smart_chunk_rotate(stacks, value);
	}
}


/**
 * Chunking: Get the chunks limits.
 * Depending on the value push the chunks towards stack_b.
 * 
 * @param stacks 
 */
void	chunking(t_stacks *stacks)
{
	int	value;
	int	counter;

	counter = 0;
	value = chunk_limit(stacks, counter);
	push_chunk(stacks, value, counter);
}

void	rotate_max_b(t_stacks *stacks)
{
	int	mid;
	int	max;
	int	index_max;

	if (STACK_B == NULL)
		return ;	
	while (DATA_B != max)
	{
		max = get_max(STACK_B);
		mid = SIZE_B / 2;
		index_max = get_index(STACK_B, max);
		if (index_max <= mid)
			op_rb(stacks);
		else
			op_rrb(stacks);
	}
}

void	push_biggest_b_to_a(t_stacks *stacks)
{
	int	max;

	if (STACK_B == NULL)
		return ;
	while (STACK_B != NULL)
	{
		max = get_max(STACK_B);
		if (DATA_B == max)
			op_pa(stacks);
		else
			rotate_max_b(stacks);
	}
}

void	sort_big_numbers(t_stacks *stacks)
{
	int	min;

	if (!STACK_A)
		return ;
	chunking(stacks);
	while (!is_sorted(STACK_A))
	{
		min = get_min(STACK_A);
		if (DATA_A == min && SIZE_A > 3)
			op_pb(stacks);
		else
			rotate_min_a(stacks);
		if (SIZE_A <= 3)
			sort_size_3(stacks);
	}
	while (STACK_B != NULL)
		push_biggest_b_to_a(stacks);
}