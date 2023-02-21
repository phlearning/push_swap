/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:38:37 by pvong             #+#    #+#             */
/*   Updated: 2023/02/21 10:15:26 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	part(int *array, int len)
{
	int		inf;
	int		sup;
	int		tmp[len];
	int		i;

	inf = 0;
	sup = len - 1;
	i = -1;
	while (++i < len - 1)
		if (array[i] > array[len - 1])
			tmp[sup--] = array[i];
		else
			tmp[inf++] = array[i];
	tmp[inf] = array[len - 1];
	i = -1;
	while (++i < len)
		array[i] = tmp[i];
	return (inf);
}

void	reg_quick_sort(int *array, int len)
{
	int		i;

	if (len < 2)
		return ;
	i = part(array, len);
	if (i)
		reg_quick_sort(array, i);
	if (i != len - 1)
		reg_quick_sort(array + i + 1, len - i - 1);
}
