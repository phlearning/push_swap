/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 23:30:03 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	if (is_sorted(STACK_A))
		return ;
	if (stacks->size_a <= 3)
		sort_size_3(stacks);
	// else if (stacks->size_a <= 5)
	// 	sort_size_5(stacks);
	else
		sort_big_numbers(stacks);
}