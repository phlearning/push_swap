/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:01:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 00:02:43 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	quick_sort_a(t_stacks *stacks, int len)
{
	int	median;
	int	nb_elem;
	int	is_under;

	if (is_len_sorted(STACK_A, len))
		return (1);
	nb_elem = len;
	if (nb_elem && len <= 3)
	{
		sort_3(stacks, len);
		return (1);
	}
	is_under = 0;
	if ((is_under == 0) && !get_median(STACK_A, len, &median))
		return (0);
	while (len != (nb_elem / 2 + nb_elem % 2))
	{
		if (DATA_A1 < median && (len--))
			op_pb(stacks);
		else
		{
			is_under++;
			op_ra(stacks);
			// if (compare_stack_to_value(STACK_A, median))
			// 	rotate_smaller_strict_a(stacks, median, &is_under);
			// else
			// 	op_ra(stacks);
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
	if (nb_elem && !get_median(STACK_B, len, &median))
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
			is_under++;
			op_rb(stacks);
		}
	}
	while (nb_elem / 2 != SIZE_B && is_under)
	{
		if (is_under > 0)
		{
			op_rrb(stacks);
			is_under--;
		}
	}
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}
