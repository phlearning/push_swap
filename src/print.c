/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 13:46:11 by pvong            ###   ########.fr       */
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
	ft_printf("\nStack_a & Stack_b\n");
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a != NULL)
		{
			ft_printf("stack_a: %d (%p)\t", tmp_a->data, tmp_a);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("\t\t\t\t");
		if (tmp_b != NULL)
		{
			ft_printf("stack_b: %d (%p)\t", tmp_b->data, tmp_b);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
	free(tmp_a);
	free(tmp_b);
}
