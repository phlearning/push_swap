/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:18:20 by pvong             #+#    #+#             */
/*   Updated: 2023/02/17 14:43:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_cmds(t_stacks *stacks)
{
	stacks->cmds.nb_cmds = 0;
	stacks->cmds.nb_sa = 0;
	stacks->cmds.nb_sb = 0;
	stacks->cmds.nb_ss = 0;
	stacks->cmds.nb_ra = 0;
	stacks->cmds.nb_rb = 0;
	stacks->cmds.nb_rr = 0;
	stacks->cmds.nb_rra = 0;
	stacks->cmds.nb_rrb = 0;
	stacks->cmds.nb_rrr = 0;
	stacks->cmds.nb_pa = 0;
	stacks->cmds.nb_pb = 0;
}

void	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->tail_a = NULL;
	stacks->stack_b = NULL;
	stacks->tail_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	stacks->min = 0;
	stacks->max = 0;
	stacks->sorted_tab = NULL;
	stacks->nb_chunks = 0;
	init_cmds(stacks);
}
