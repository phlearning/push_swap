/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:47:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 17:02:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swap_a: Swap the first 2 elements in stack_a  */
void	op_sa(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	swap(&stacks->stack_a);
	ft_printf("sa\n");
}

/* Swap_b: Swap the first 2 elements in stack_b */
void	op_sb(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	swap(&stacks->stack_b);
	ft_printf("sb\n");
}

/* Swap_both: swap the first 2 elements in both stack_a and stack_b */
void	op_ss(t_stacks *stacks)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		swap(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		swap(&stacks->stack_b);
	ft_printf("ss\n");
}

/* Rotate_a: Rotate the stack_a towards the top */
void	op_ra(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	rotate(&stacks->stack_a);
	ft_printf("ra\n");
}

/* Rotate_b: Rotate the stack_a towards the top */
void	op_rb(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	rotate(&stacks->stack_b);
	ft_printf("rb\n");
}

void	op_rr(t_stacks *stacks)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		rotate(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		rotate(&stacks->stack_b);
	ft_printf("rr\n");
}

/* Reverse_Rotate_a: Rotate the stack_a towards the bottom */
void	op_rra(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	rrotate(&stacks->stack_a);
	ft_printf("rra\n");
}

/* Reverse_Rotate_b: Rotate the stack_a towards the bottom */
void	op_rrb(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	rrotate(&stacks->stack_b);
	ft_printf("rrb\n");
}

void	op_rrr(t_stacks *stacks)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		rrotate(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		rrotate(&stacks->stack_b);
	ft_printf("rrr\n");
}

/* Push_a: Push the first element of stack_b to stack_a.
	Do nothing if b is empty */
void	op_pa(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	push(&stacks->stack_b, &stacks->stack_a);
	stacks->size_a++;
	stacks->size_b--;
	ft_printf("pa\n");
}

/* Push_b: Push the first element of stack_a to stack_b.
	Do nothing if a is empty */
void	op_pb(t_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	push(&stacks->stack_a, &stacks->stack_b);
	stacks->size_a--;
	stacks->size_b++;
	ft_printf("pb\n");
}