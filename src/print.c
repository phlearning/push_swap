/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:47:49 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printlist(t_node *node)
{
	t_node	*tmp;

	if (node != NULL)
		tmp = node;
	else
		return ;
	ft_printf("---------------\n");
	while (tmp->next != node)
	{
		ft_printf("node: %d (%p)\n", tmp->data, tmp);
		tmp = tmp->next;
	}
	ft_printf("node: %d (%p)\n", tmp->data, tmp);
	ft_printf("---------------\n");
}

/* void	printlist2(t_stacks *stacks)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		count_a;
	int		count_b;

	tmp_a = stacks->stack_a;
	tmp_b = stacks->stack_b;
	count_a = 0;
	count_b = 0;
	ft_printf("\n------------------Stack_a & Stack_b------------------\n");
	ft_printf("stack_a_len: %d\t\t\t", stacks->size_a);
	ft_printf("stack_b_len: %d\n", stacks->size_b);
	while (count_a < SIZE_A || count_b < SIZE_B)
	{
		if (SIZE_A > 0 && count_a < SIZE_A)
		{
			ft_printf("stack_a[%d]: %d (%p)\t", tmp_a->index, tmp_a->data, tmp_a);
			tmp_a = tmp_a->next;
			++count_a;
		}
		else
			ft_printf("\t\t\t\t");
		if (SIZE_B > 0 && count_b < SIZE_B)
		{
			ft_printf("stack_b[%d]: %d (%p)\t", tmp_b->index, tmp_b->data, tmp_b);
			tmp_b = tmp_b->next;
			++count_b;
		}
		ft_printf("\n");
	}
	ft_printf("-----------------------------------------------------\n");
} */

void	printcmds(t_stacks *stacks)
{
	ft_printf("\n----CMDS----\n");
	ft_printf("\nNb cmds: %d\n", stacks->cmds.nb_cmds);
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
