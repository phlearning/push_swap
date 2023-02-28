/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:42:40 by pvong             #+#    #+#             */
/*   Updated: 2023/02/28 10:55:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* CMDS SHORTCUTS */
/* ------------- */
/* STACKS SHORTCUT */
# define STACK_A stacks->stack_a
# define STACK_A_NEXT stacks->stack_a->next
# define DATA_A stacks->stack_a->data
# define DATA_A_NEXT stacks->stack_a->next->data
# define DATA_A1 stacks->stack_a->data
# define DATA_A2 stacks->stack_a->next->data
# define DATA_A3 stacks->stack_a->next->next->data
# define SIZE_A stacks->size_a
/* --- */
# define STACK_B stacks->stack_b
# define STACK_B_NEXT stacks->stack_b->next
# define DATA_B stacks->stack_b->data
# define DATA_B_NEXT stacks->stack_b->next->data
# define DATA_B1 stacks->stack_b->data
# define DATA_B2 stacks->stack_b->next->data
# define DATA_B3 stacks->stack_b->next->next->data
# define SIZE_B stacks->size_b
/* --- */
# define STACK_SIZE stacks->size_start
# define FLAG stacks->flagprint
/* --------------------------- */

#endif