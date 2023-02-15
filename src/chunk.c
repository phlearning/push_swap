/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:22 by pvong             #+#    #+#             */
/*   Updated: 2023/02/15 18:08:18 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Get limits of each chunks. The counter tells us if we already initiated
the limits or not and let us add to the size. */
int	chunk_limit(t_stacks *stacks, int counter)
{
	int	limit;
	int	size_chunk;
	int	index;

	size_chunk = STACK_SIZE / get_chunks(stacks);
	index = (counter + 1) * size_chunk;
	if (index < STACK_SIZE)
	{
		limit = SORTED_TAB[index];
		return (limit);
	}
	return (0);
}

int	chunk_size(t_stacks *stacks)
{
	int	size_chunk;

	size_chunk = STACK_SIZE / get_chunks(stacks);
	return (size_chunk);
}

int	get_chunks(t_stacks *stacks)
{
	int	chunks;

	chunks = square_root(STACK_SIZE) / 2;
	return (chunks);
}