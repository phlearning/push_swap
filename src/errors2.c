/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:20:20 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 16:55:19 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_all_args(t_node **stack_a, char **av)
{
	if (check_error(av + 1) == -1)
		exit_error("Error");
	insert_all(stack_a, av + 1);
	return (0);
}
