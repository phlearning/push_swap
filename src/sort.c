/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:41:53 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 01:02:47 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	if (is_sorted(STACK_A))
		return ;
	if (stacks->size_a <= 5)
		quick_sort_a(stacks, SIZE_A);
	else
		sort_big_numbers(stacks);
}
