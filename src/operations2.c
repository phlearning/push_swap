/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:47:25 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 07:38:01 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	addcommands(t_stacks *stacks, char *cmds)
{
	stacks->cmds.nb_cmds++;
	if (!ft_strncmp(cmds, "sa", 10))
		stacks->cmds.nb_sa++;
	if (!ft_strncmp(cmds, "sb", 10))
		stacks->cmds.nb_sb++;
	if (!ft_strncmp(cmds, "ss", 10))
		stacks->cmds.nb_ss++;
	if (!ft_strncmp(cmds, "ra", 10))
		stacks->cmds.nb_ra++;
	if (!ft_strncmp(cmds, "rb", 10))
		stacks->cmds.nb_rb++;
	if (!ft_strncmp(cmds, "rr", 10))
		stacks->cmds.nb_rr++;
	if (!ft_strncmp(cmds, "rra", 10))
		stacks->cmds.nb_rra++;
	if (!ft_strncmp(cmds, "rrb", 10))
		stacks->cmds.nb_rrb++;
	if (!ft_strncmp(cmds, "rrr", 10))
		stacks->cmds.nb_rrr++;
	if (!ft_strncmp(cmds, "pa", 10))
		stacks->cmds.nb_pa++;
	if (!ft_strncmp(cmds, "pb", 10))
		stacks->cmds.nb_pb++;
	change_index(stacks, cmds);
}

/* Swap_a: Swap the first 2 elements in stack_a  */
void	op_sa(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	swap(&stacks->stack_a);
	addcommands(stacks, "sa");
	if (flag == 1)
		ft_printf("sa\n");
}

/* Swap_b: Swap the first 2 elements in stack_b */
void	op_sb(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return ;
	swap(&stacks->stack_b);
	addcommands(stacks, "sb");
	if (flag == 1)
		ft_printf("sb\n");
}

/* Swap_both: swap the first 2 elements in both stack_a and stack_b */
void	op_ss(t_stacks *stacks, int flag)
{
	if (stacks->stack_a == NULL && stacks->stack_b == NULL)
		return ;
	if (stacks != NULL && stacks->stack_a != NULL)
		swap(&stacks->stack_a);
	if (stacks != NULL && stacks->stack_b != NULL)
		swap(&stacks->stack_b);
	addcommands(stacks, "ss");
	if (flag == 1)
		ft_printf("ss\n");
}

/* Rotate_a: Rotate the stack_a towards the top */
void	op_ra(t_stacks *stacks, int flag)
{
	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	rotate(&stacks->stack_a);
	addcommands(stacks, "ra");
	if (flag == 1)
		ft_printf("ra\n");
}
