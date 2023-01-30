/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:40 by pvong             #+#    #+#             */
/*   Updated: 2023/01/30 17:00:33 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_node(t_node **head_ref, int key)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *head_ref;
	if (tmp != NULL && tmp->data == key)
	{
		*head_ref = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && tmp->data != key)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(tmp);
}

void	sort_linked_list(t_node **head_ref)
{
	t_node	*current;
	t_node	*index;
	int		tmp;

	current = *head_ref;
	if (head_ref == NULL)
		return ;
	else
	{
		while (current != NULL)
		{
			index = current->next;
			while (index != NULL)
			{
				if (current->data > index->data)
				{
					tmp = current->data;
					current->data = index->data;
					index->data = tmp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

int	main(int ac, char **av)
{
	t_node	*pile_a;
	t_node	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (0);
		check_and_split(&pile_a, av);
	}
	if (ac > 2)
	{
		check_all_args(&pile_a, av);
	}
	// Printpiles
	printlist2(pile_a, pile_b);
	free_both_stacks(pile_a, pile_b);
	return (0);
}
