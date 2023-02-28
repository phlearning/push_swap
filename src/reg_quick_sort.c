/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:38:37 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 00:37:23 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	part(int *array, int len)
{
	int		beg;
	int		last;
	int		*tmp;
	int		i;

	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		return (0);
	beg = 0;
	last = len - 1;
	i = -1;
	while (++i < len - 1)
	{
		if (array[i] > array[len - 1])
			tmp[last--] = array[i];
		else
			tmp[beg++] = array[i];
	}
	tmp[beg] = array[len - 1];
	i = -1;
	while (++i < len)
		array[i] = tmp[i];
	free(tmp);
	return (beg);
}

void	reg_quick_sort(int *array, int len)
{
	int		partition;

	if (len < 2)
		return ;
	partition = part(array, len);
	if (partition)
		reg_quick_sort(array, partition);
	if (partition != len - 1)
		reg_quick_sort(array + partition + 1, len - partition - 1);
}
