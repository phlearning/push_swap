/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 18:44:19 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_node *node)
{
	while (node != NULL)
	{
		ft_printf("node: %d (%p)\n", node->data, node);
		node = node->next;
	}
}

void	printlist2(t_stacks *stacks)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = stacks->stack_a;
	tmp_b = stacks->stack_b;
	ft_printf("\n------------------Stack_a & Stack_b------------------\n");
	ft_printf("stack_a_len: %d\t\t\t", stacks->size_a);
	ft_printf("stack_b_len: %d\n", stacks->size_b);
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a != NULL)
		{
			ft_printf("stack_a[%d]: %d (%p)\t", tmp_a->index, tmp_a->data, tmp_a);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("\t\t\t\t");
		if (tmp_b != NULL)
		{
			ft_printf("stack_b[%d]: %d (%p)\t", tmp_b->index, tmp_b->data, tmp_b);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----------------------------------------------------\n");
	free(tmp_a);
	free(tmp_b);
}

void	printcmds(t_stacks *stacks)
{
	ft_printf("\n----CMDS----\n");
	ft_printf("nb_sa: %d\n", NB_SA);
	ft_printf("nb_sb: %d\n", NB_SB);
	ft_printf("nb_ss: %d\n", NB_SS);
	ft_printf("nb_ra: %d\n", NB_RA);
	ft_printf("nb_rb: %d\n", NB_RB);
	ft_printf("nb_rr: %d\n", NB_RR);
	ft_printf("nb_rra: %d\n", NB_RRA);
	ft_printf("nb_rrb: %d\n", NB_RRB);
	ft_printf("nb_rrr: %d\n", NB_RRR);
	ft_printf("nb_pa: %d\n", NB_PA);
	ft_printf("nb_pb: %d\n", NB_PB);
	ft_printf("\n------------\n");
}