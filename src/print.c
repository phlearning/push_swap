/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/01/30 14:55:16 by pvong            ###   ########.fr       */
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

void	printlist2(t_node *node, t_node *node2)
{
	ft_printf("\nPile_a & Pile_b\n");
	while (node != NULL || node2 != NULL)
	{
		if (node != NULL)
		{
			ft_printf("node: %d (%p)\t", node->data, node);
			node = node->next;
		}
		else
			ft_printf("\t\t\t\t");
		if (node2 != NULL)
		{
			ft_printf("node2: %d (%p)\t", node2->data, node2);
			node2 = node2->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
