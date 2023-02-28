/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:44:18 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 07:39:32 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Push_a: Push the first element of stack_b to stack_a.
	Do nothing if b is empty.
	The index doesn't matter here it will be changed
	by the function change_index.*/
void	op_pa(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_b == NULL || SIZE_B == 0)
		return ;
	push(&stacks->stack_b, &stacks->stack_a);
	stacks->size_a++;
	stacks->size_b--;
	addcommands(stacks, "pa");
	if (flag == 1)
		ft_printf("pa\n");
}

/* Push_b: Push the first element of stack_a to stack_b.
	Do nothing if a is empty
	The index doesn't matter here it will be changed
	by the function change_index*/
void	op_pb(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_a == NULL || SIZE_A == 0)
		return ;
	push(&stacks->stack_a, &stacks->stack_b);
	stacks->size_a--;
	stacks->size_b++;
	addcommands(stacks, "pb");
	if (flag == 1)
		ft_printf("pb\n");
}
