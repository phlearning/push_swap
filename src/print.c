/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:53:27 by pvong             #+#    #+#             */
/*   Updated: 2023/01/18 14:43:05 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printnodeaddress(t_node *node, int nbprint)
{
	ft_printf("%d pointer: %p\n", nbprint, node);
}

void	printlist(t_node *node)
{
	while (node != NULL)
	{
		ft_printf("node: %d (%p)\n", node->data, node);
		node = node->next;
	}
}

void	ft_printpilea(t_node *pile)
{
	ft_printf("pile_a: \n");
	printlist(pile);
	ft_printf("\n");
}

void	ft_printpileb(t_node *pile)
{
	ft_printf("pile_b: \n");
	printlist(pile);
	ft_printf("\n");
}