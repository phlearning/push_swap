/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:48:40 by pvong             #+#    #+#             */
/*   Updated: 2023/02/06 17:05:11 by pvong            ###   ########.fr       */
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

/**
 * Push_swap: With different operations (swap, push, rotate)(a/b/r) 
 * sort the pile_a. Show the different operations to sort the pile_a.
 * Can use 2 piles (a or b) to sort.
 * 
 * TODO: 1. Check inputs for errors
 * TODO: 2.	Insert inputs
 * TODO: 3. Sort and show operations
 * TODO: 4.	Free
 * @param ac 
 * @param av 
 * @return int 
 */

int	main(int ac, char **av)
{
	t_stacks *stacks;

	stacks = my_malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	init_stacks(stacks);
	check_inputs(ac, av, stacks);
	ft_printf("stack_a_len: %d\t", stacks->size_a);
	ft_printf("stack_b_len: %d\n", stacks->size_b);
	// Printpiles before sorting
	printlist2(stacks);

	// sort(&stacks->stack_a);
	
	// Printpiles after sorting
	// ft_printf("-----Sort-----\n");
	printlist2(stacks);
	// Free piles
	free_stacks(stacks);
	return (0);
}
