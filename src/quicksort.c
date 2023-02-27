/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:01:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 16:52:44 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_smaller_strict(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data < value)
			return (tmp->index);
		if (tmp->next->data < value)
			return (tmp->next->index);
		tmp = tmp->next;
	}

	return (0);
}

int	lastindex_smaller_strict(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp->next != node)
	{
		if (tmp->data < value)
			index = tmp->index;
		if (tmp->next->data < value)
			index = tmp->next->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_smaller_strict_than_a(t_stacks *stacks, int value)
{
	int	index;
	int	first_pos;
	int	second_pos;

	first_pos = index_smaller_strict(STACK_A, value);
	second_pos = lastindex_smaller_strict(STACK_A, value);
	if (compare_pos(first_pos, second_pos, stacks, "A"))
		index = first_pos;
	else
		index = second_pos;
	return (index);
}

void	rotate_smaller_strict_a(t_stacks *stacks, int value, int *count)
{
	int	smaller;
	int	half_size;

	if (DATA_A >= value)
	{
		half_size = SIZE_A /2 + SIZE_A % 2;
		smaller = index_smaller_strict_than_a(stacks, value);
		if (smaller <= half_size)
		{
			op_ra(stacks);
			(*count)++;
		}
		else
		{
			op_rra(stacks);
			(*count)--;
		}
	}
}

int	index_bigger_equal(t_node *node, int value)
{
	t_node	*tmp;

	tmp = node;
	while (tmp->next != node)
	{
		if (tmp->data >= value)
			return (tmp->index);
		if (tmp->next->data >= value)
			return (tmp->next->index);
		tmp = tmp->next;
	}

	return (0);
}

int	lastindex_bigger_equal(t_node *node, int value)
{
	int		index;
	t_node	*tmp;

	tmp = node;
	index = 0;
	while (tmp->next != node)
	{
		if (tmp->data >= value)
			index = tmp->index;
		if (tmp->next->data >= value)
			index = tmp->next->index;
		tmp = tmp->next;
	}
	return (index);
}

int	index_bigger_equal_b(t_stacks *stacks, int value)
{
	int	index;
	int	first_pos;
	int	second_pos;

	first_pos = index_bigger_equal(STACK_B, value);
	second_pos = lastindex_bigger_equal(STACK_B, value);
	if (compare_pos(first_pos, second_pos, stacks, "B"))
		index = first_pos;
	else
		index = second_pos;
	return (index);
}

void	rotate_bigger_equal_b(t_stacks *stacks, int value, int *count)
{
	int	smaller;
	int	half_size;

	if (DATA_B < value)
	{
		half_size = SIZE_B /2 + SIZE_B % 2;
		smaller = index_bigger_equal_b(stacks, value);
		if (smaller <= half_size)
		{
			op_rb(stacks);
			(*count)++;
		}
		else
		{
			op_rrb(stacks);
			(*count)--;
		}
	}
}

int	quick_sort_a(t_stacks *stacks, int len)
{
	int	median;
	int	nb_elem;
	int	is_under;

	// ft_printf("Size_a: %d | Size_b: %d | len: %d\n", SIZE_A, SIZE_B, len);
	// sleep(1);
	if (is_len_sorted(STACK_A, len))
			return (1);
	nb_elem = len;
	if (nb_elem && len <= 3)
	{
		sort_3(stacks, len);
		return (1);
	}
	is_under = 0;
	if ((is_under == 0) && !get_median2(STACK_A, len, &median))
		return (0);
	while (len != (nb_elem / 2 + nb_elem % 2))
	{
		if (DATA_A1 < median && (len--))
			op_pb(stacks);
		else
		{
			// is_under++;
			// op_ra(stacks);
			rotate_smaller_strict_a(stacks, median, &is_under);
		}
	}
	while (((nb_elem / 2 + nb_elem % 2) != SIZE_A) && is_under)
	{
		if (is_under > 0)
		{
			is_under--;
			op_rra(stacks);
		}
		if (is_under < 0)
		{
			is_under++;
			op_ra(stacks);
		}
		// sleep(1);
	}
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}

/**
 * quicksort_b: if the len of the stack is already reversed sorted 
 * then push to stack_a.
 * If the len <= 3 then do optimize sort for 3 and push it to stack_a;
 * Else if check if the top is > to the median:
 * push to stack_a if yes.
 * Else rotate till the top is > median and count rotate_b;
 * Revert the rotate to before while the nb of elements isn't half.
 * @param stacks 
 * @param len 
 * @return int 
 */
int	quick_sort_b(t_stacks *stacks, int len)
{
	int	median;
	int	nb_elem;
	int	is_under;

	is_under = 0;
	if (is_under == 0 && is_len_rev_sorted(STACK_B, len))
	{
		while (len)
		{
			op_pa(stacks);
			len--;
		}
	}
	if (len <= 3)
	{
		push_sort_3_b_to_a(stacks, len);
		return (1);
	}
	nb_elem = len;
	if (nb_elem && !get_median2(STACK_B, len, &median))
		return (0);
	while (len != nb_elem / 2)
	{
		if (DATA_B1 >= median && (len))
		{
			op_pa(stacks);
			len--;
		}
		else
		{
			++is_under;
			op_rb(stacks);
		}
	}
	while (nb_elem / 2 != SIZE_B && is_under)
	{
		op_rrb(stacks);
		is_under--;
	}
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}