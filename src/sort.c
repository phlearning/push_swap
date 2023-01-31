/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/01/31 18:40:04 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_node **pile_a, t_node **pile_b)
{
	int		tmp;
	t_node	*tmpa;
	t_node	*tmpb;

	/* Check if empty */
	if (is_empty(*pile_a))
		return ;
	tmpa = *pile_a;
	tmpb = *pile_b;
	while (tmpa)
	{
		tmp = tmpa->data;
		while (tmpb && tmp < peek(0, pile_b))
			
	}
}