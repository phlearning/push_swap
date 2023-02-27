/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:38:47 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:40:53 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Put the index to the stack_a and stack_b */
void	index_reput(t_stacks *stacks)
{
	put_index_stack_a(stacks);
	put_index_stack_b(stacks);
}

void	change_index(t_stacks *stacks, char *cmds)
{
	if (!ft_strncmp(cmds, "sa", 10))
		index_sa(stacks);
	if (!ft_strncmp(cmds, "sb", 10))
		index_sb(stacks);
	if (!ft_strncmp(cmds, "ss", 10))
		index_ss(stacks);
	if (!ft_strncmp(cmds, "ra", 10))
		put_index_stack_a(stacks);
	if (!ft_strncmp(cmds, "rb", 10))
		put_index_stack_b(stacks);
	if (!ft_strncmp(cmds, "rr", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "rra", 10))
		put_index_stack_a(stacks);
	if (!ft_strncmp(cmds, "rrb", 10))
		put_index_stack_b(stacks);
	if (!ft_strncmp(cmds, "rrr", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "pa", 10))
		index_reput(stacks);
	if (!ft_strncmp(cmds, "pb", 10))
		index_reput(stacks);
}
