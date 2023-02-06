/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:18:20 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 18:27:25 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
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

	int		nb_sa;
	int		nb_sb;
	int		nb_ss;
	int		nb_ra;
	int		nb_rb;
	int		nb_rr;
	int		nb_rra;
	int		nb_rrb;
	int		nb_rrr;