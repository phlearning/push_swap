/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:43:30 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 07:38:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Rotate_b: Rotate the stack_a towards the top */
void	op_rb(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	rotate(&stacks->stack_b);
	addcommands(stacks, "rb");
	if (flag == 1)
		ft_printf("rb\n");
}

void	op_rr(t_stacks *stacks, int flag)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		rotate(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		rotate(&stacks->stack_b);
	addcommands(stacks, "rr");
	if (flag == 1)
		ft_printf("rr\n");
}

/* Reverse_Rotate_a: Rotate the stack_a towards the bottom */
void	op_rra(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	rrotate(&stacks->stack_a);
	addcommands(stacks, "rra");
	if (flag == 1)
		ft_printf("rra\n");
}

/* Reverse_Rotate_b: Rotate the stack_a towards the bottom */
void	op_rrb(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	rrotate(&stacks->stack_b);
	addcommands(stacks, "rrb");
	if (flag == 1)
		ft_printf("rrb\n");
}

void	op_rrr(t_stacks *stacks, int flag)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		rrotate(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		rrotate(&stacks->stack_b);
	addcommands(stacks, "rrr");
	if (flag == 1)
		ft_printf("rrr\n");
}
