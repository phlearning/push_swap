/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:59:22 by pvong             #+#    #+#             */
/*   Updated: 2023/02/08 17:49:11 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunks(t_stacks *stacks)
{
	int	chunks;

	chunks = square_root(SIZE_A) / 2;
	return (chunks);
}