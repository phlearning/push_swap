/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:01:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/23 21:54:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	recursive_a = -1;
int	recursive_b = -1;

int	quick_sort_a(t_stacks *stacks, int len)
{
	int	median;
	int	nb_elem;
	int	is_under;

	recursive_a++;
	// ft_printf("Size_a: %d | Size_b: %d | len: %d\n", SIZE_A, SIZE_B, len);
	// sleep(1);
	if (is_len_sorted(STACK_A, len))
		{
			// ft_printf("IS_SORTED\n");
			// sleep(1);
			return (1);
		}
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
			is_under++;
			op_ra(stacks);
		}
	}
	while (((nb_elem / 2 + nb_elem % 2) != SIZE_A) && is_under)
	{
		is_under--;
		op_rra(stacks);
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
	recursive_b++;
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
/* 		ft_printf("recursive_b: %d\n", recursive_b);
		ft_printf("is_under: %d | len: %d | data_b1: %d next: %d \n", is_under, len, DATA_B, DATA_B2);
		ft_printf("nb_elem/2 : %d | SIZE_B: %d\n", nb_elem/2, SIZE_B);
		sleep(1); */
	while (nb_elem / 2 != SIZE_B && is_under)
	{
		op_rrb(stacks);
		is_under--;
/* 		ft_printf("is_under: %d | len: %d | data_b1: %d next: %d \n", is_under, len, DATA_B, DATA_B1);
		ft_printf("nb_elem/2 : %d | SIZE_B: %d\n", nb_elem/2, SIZE_B);
		sleep(1); */
	}
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}