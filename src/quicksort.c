/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:01:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:04:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_or_rotate_qcka(t_stacks *stacks, \
		int nb_elem, int *len, int *is_under)
{
	int	median;

	get_median(stacks->stack_a, *len, &median);
	while (*len != (nb_elem / 2 + nb_elem % 2))
	{
		if (stacks->stack_a->data < median && (*len)--)
			op_pb(stacks, stacks->flagprint);
		else
		{
			(*is_under)++;
			op_ra(stacks, stacks->flagprint);
		}
	}
}

void	reverse_rotate_qcka(t_stacks *stacks, int nb_elem, int *is_under)
{
	while (((nb_elem / 2 + nb_elem % 2) != stacks->size_a) && *is_under)
	{
		if (*is_under > 0)
		{
			(*is_under)--;
			op_rra(stacks, stacks->flagprint);
		}
		if (*is_under < 0)
		{
			(*is_under)++;
			op_ra(stacks, stacks->flagprint);
		}
	}
}

int	quick_sort_a(t_stacks *stacks, int len)
{
	int	median;
	int	nb_elem;
	int	is_under;

	if (is_len_sorted(stacks->stack_a, len))
		return (1);
	nb_elem = len;
	if (nb_elem && len <= 3)
	{
		sort_3(stacks, len);
		return (1);
	}
	is_under = 0;
	if ((is_under == 0) && !get_median(stacks->stack_a, len, &median))
		return (0);
	push_or_rotate_qcka(stacks, nb_elem, &len, &is_under);
	reverse_rotate_qcka(stacks, nb_elem, &is_under);
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}

void	push_or_rotate_qckb(t_stacks *stacks, \
		int nb_elem, int *len, int *is_under)
{
	int	median;

	get_median(stacks->stack_b, *len, &median);
	while (*len != nb_elem / 2)
	{
		if (stacks->stack_b->data >= median && (*len))
		{
			op_pa(stacks, stacks->flagprint);
			(*len)--;
		}
		else
		{
			(*is_under)++;
			op_rb(stacks, stacks->flagprint);
		}
	}
	while (nb_elem / 2 != stacks->size_b && *is_under)
	{
		if ((*is_under) > 0)
		{
			op_rrb(stacks, stacks->flagprint);
			(*is_under)--;
		}
	}
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
	if (is_under == 0 && is_len_rev_sorted(stacks->stack_b, len))
	{
		while (len)
		{
			op_pa(stacks, stacks->flagprint);
			len--;
		}
	}
	if (len <= 3)
	{
		push_sort_3_b_to_a(stacks, len);
		return (1);
	}
	nb_elem = len;
	if (nb_elem && !get_median(stacks->stack_b, len, &median))
		return (0);
	push_or_rotate_qckb(stacks, nb_elem, &len, &is_under);
	quick_sort_a(stacks, nb_elem / 2 + nb_elem % 2);
	quick_sort_b(stacks, nb_elem / 2);
	return (1);
}
