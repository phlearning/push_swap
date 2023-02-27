/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:18:13 by pvong             #+#    #+#             */
/*   Updated: 2023/02/27 18:03:28 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Check_sign: look for duplicate sign or sign without number
 * 
 * @param str 
 * @return int 
 */
int	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (!str[i + 1])
				return (-1);
			i++;
			if (str[i] == '-' || str[i] == '+')
				return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * Check_number: Look for numbers and signs
 * 
 * @param str 
 * @return int 
 */
int	check_number(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || \
			(str[i] == '-' || str[i] == '+')))
			return (-1);
		i++;
	}
	return (0);
}

int	*transf_args_to_tab(char **str)
{
	int	i;
	int	*tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(int) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (str[i])
	{
		tmp[i] = ft_atoi(str[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	check_dupe(char **str)
{
	int	*tmp;
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (str[len])
		len++;
	tmp = transf_args_to_tab(str);
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (tmp[i] == tmp[j])
			{
				free(tmp);
				return (-1);
			}
		}
	}
	free(tmp);
	return (0);
}

/**
 * Check_error: Check within a **str for duplicates numbers,
 * double signs, characters other than numbers
 * and if so returns -1;
 * 
 * @param str 
 * @return int 
 */
int	check_error(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_number(str[i]) == -1 || check_sign(str[i]) == -1)
			return (-1);
		if (ft_atol(str[i]) >= 2147483648 || ft_atol(str[i]) < -2147483648)
			return (-1);
		i++;
	}
	if (check_dupe(str) == -1)
		return (-1);
	return (0);
}
