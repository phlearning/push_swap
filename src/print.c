/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 11:04:24 by pvong            ###   ########.fr       */
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
	while (count_a < stacks->size_a || count_b < stacks->size_b)
	{
		if (stacks->size_a > 0 && count_a < stacks->size_a)
		{
			ft_printf("stack_a[%d]: %d (%p)\t", tmp_a->index, tmp_a->data, tmp_a);
			tmp_a = tmp_a->next;
			++count_a;
		}
		else
			ft_printf("\t\t\t\t");
		if (stacks->size_b > 0 && count_b < stacks->size_b)
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
	ft_printf("nb_sa: %d\n", stacks->cmds.nb_sa);
	ft_printf("nb_sb: %d\n", stacks->cmds.nb_sb);
	ft_printf("nb_ss: %d\n", stacks->cmds.nb_ss);
	ft_printf("nb_ra: %d\n", stacks->cmds.nb_ra);
	ft_printf("nb_rb: %d\n", stacks->cmds.nb_rb);
	ft_printf("nb_rr: %d\n", stacks->cmds.nb_rr);
	ft_printf("nb_rra: %d\n", stacks->cmds.nb_rra);
	ft_printf("nb_rrb: %d\n", stacks->cmds.nb_rrb);
	ft_printf("nb_rrr: %d\n", stacks->cmds.nb_rrr);
	ft_printf("nb_pa: %d\n", stacks->cmds.nb_pa);
	ft_printf("nb_pb: %d\n", stacks->cmds.nb_pb);
	ft_printf("\n------------\n");
}
