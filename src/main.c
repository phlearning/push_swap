/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:40 by pvong             #+#    #+#             */
/*   Updated: 2023/01/18 16:12:25 by pvong            ###   ########.fr       */
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

int	main(void)
{
	t_node	*pile_a;
	t_node	*pile_b;

	// Mettre 1, 2, 3 dans la pile_a: 3,2,1
	pile_a = NULL;
	insert_beg(&pile_a, 1);
	insert_beg(&pile_a, 2);
	insert_beg(&pile_a, 3);

	// Mettre 4,5,6 dans pile_b: 6, 5, 4
	pile_b = NULL;
	insert_beg(&pile_b, 4);
	insert_beg(&pile_b, 5);
	insert_beg(&pile_b, 6);

	// Printpiles
	printlist2(pile_a, pile_b);

	ft_printf("Push\n");
	push(&pile_b, &pile_a);
		push(&pile_b, &pile_a);
			push(&pile_b, &pile_a);
				push(&pile_b, &pile_a);
	// Printpiles
	printlist2(pile_a, pile_b);
	free_stack(pile_a);
	free_stack(pile_b);
	return (0);
}
