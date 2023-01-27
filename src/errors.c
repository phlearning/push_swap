/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:18:13 by pvong             #+#    #+#             */
/*   Updated: 2023/01/27 19:50:01 by pvong            ###   ########.fr       */
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
	tmp = my_malloc(sizeof(int) * i);
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
				my_free(tmp);
				return (-1);
			}
		}
	}
	my_free(tmp);
	return (0);
}

int	check_error(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_number(str[i]) == -1 || check_sign(str[i]) == -1)
			return (-1);
		i++;
	}
	if (check_dupe(str) == -1)
		return (-1);
	return (0);
}

/**
 * Check_and_split:
 * 
 * TODO: ...
 * 1. Split into multiple args
 * 2. Check the args
 * 3. Check for duplicate numbers
 * 4. Check for double signs
 * 
 * @param pile_a 
 * @param pile_b 
 * @param ac 
 * @param av 
 * @return int 
 */
int	check_and_split(t_node **pile_a, char **av)
{
	char	**tmp;

	tmp = ft_split(av[1], ' ');
	if (check_error(tmp) == -1)
	{
		free_split(tmp);
		exit_error(DUPE_ERROR);
	}
	insert_all(pile_a, tmp);
	free_split(tmp);
	return (0);
}

void	exit_error(char *str)
{
	ft_putendl_fd(str, ERROR_FD);
	exit(1);
}