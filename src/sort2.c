/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:32:31 by pvong             #+#    #+#             */
/*   Updated: 2023/02/19 17:45:22 by pvong            ###   ########.fr       */
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

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data <= value)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->data <= value)
		return (1);
	return (0);
}

int	lastindex_by_comparaison(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp->next != node)
	{
		if (tmp->data <= value)
			index = tmp->index;
		if (tmp->next->data <= value)
			index = tmp->next->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_by_comparaison(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data <= value)
		{
			return (tmp->index);
		}
		if (tmp->next->data <= value)
		{
			return (tmp->next->index);
		}
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
	if (compare_pos(first_pos, second_pos, stacks, "A"))
		index = first_pos;
	else
		index = second_pos;
/* 	ft_printf("value[%d]: %d ||", first_pos, get_data_by_index(STACK_A, first_pos));
	ft_printf("value[%d]: %d\t->", second_pos, get_data_by_index(STACK_A, second_pos));
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
	// ft_printf("DATA[%d]: %d\n",STACK_A->index, DATA_A);
	// ft_printf("DATA[%d]: %d\n",STACK_A->prev->index, STACK_A->prev->data);
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
		if (DATA_A <= value)
		{
			op_pb(stacks);
	/* 		if (STACK_B_NEXT && DATA_B_NEXT > DATA_B)
				op_sb(stacks); */
		}	
		if (!(compare_stack_to_value(STACK_A, value)))
			value = chunk_limit(stacks, ++i);
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

void	rotate_nb_a(t_stacks *stacks, int nb)
{
	int	mid;
	int	index_nb;

	while (DATA_A != nb)
	{
		mid = SIZE_A / 2;
		index_nb = get_index(STACK_A, nb);
		if (index_nb <= mid)
			op_ra(stacks);
		else
			op_rra(stacks);
	}
}

void	rotate_nb_b(t_stacks *stacks, int nb)
{
	int	mid;
	int	index_nb;

	while (DATA_B != nb)
	{
		mid = SIZE_B / 2;
		index_nb = get_index(STACK_B, nb);
		if (index_nb <= mid)
			op_rb(stacks);
		else
			op_rrb(stacks);
	}
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

	max = get_max(STACK_B);
	if (STACK_B == NULL)
		return ;
	rotate_nb_b(stacks, max);
	if (DATA_B == max)
			op_pa(stacks);
}

void	rotate_min_b(t_stacks *stacks)
{
	int	mid;
	int	min;
	int	index_min;

	if (STACK_B == NULL)
		return ;	
	while (DATA_B != min)
	{
		min = get_min(STACK_B);
		mid = SIZE_B / 2;
		index_min = get_index(STACK_B, min);
		if (index_min <= mid)
			op_rb(stacks);
		else
			op_rrb(stacks);
	}
}

void	push_smallest_b_to_a(t_stacks *stacks)
{
	int	min;

	min = get_min(STACK_B);
	if (STACK_B == NULL)
		return ;
	rotate_nb_b(stacks, min);
	if (DATA_B == min)
			op_pa(stacks);
}

int	get_last_value(t_node *node)
{
	t_node *tmp;

	if (node == NULL)
		return (0);
	tmp = get_lastnode(node);
	return (tmp->data);
}

void	sort_big_numbers(t_stacks *stacks)
{
	int	min;

	if (!STACK_A)
		return ;
	if (is_sorted(STACK_A))
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
	{
		push_biggest_b_to_a(stacks);
	}
/* 	while (DATA_A != STACKS_MIN)
		rotate_min_a(stacks); */
}