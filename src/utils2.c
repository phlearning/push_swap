/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:28:11 by pvong             #+#    #+#             */
/*   Updated: 2023/01/31 16:25:07 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_empty(t_node *head)
{
	return (head == NULL);
}

/**
 * Insert at the end of the pile the numbers.
 * 
 * @param head_ref 
 * @param data 
 */
void	insert_all(t_node **head_ref, char **data)
{
	int	number_of_elements;

	number_of_elements = 0;
	while (data[number_of_elements])
	{
		insert_end(head_ref, ft_atoi(data[number_of_elements]));
		number_of_elements++;
	}
}

long	ft_atol(char *str)
{
	long	sign;
	int		i;
	long	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
