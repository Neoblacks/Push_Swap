/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:22:08 by amugnier          #+#    #+#             */
/*   Updated: 2023/03/10 11:38:36 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Rotates a stack in the opposite direction by moving the bottom element to
	the top. If the stack is empty or only contains one element, nothing
	happens. It first finds the bottom element and its predecessor, stores
	the current top element, sets the stack to the bottom element, sets its
	"next" pointer to the stored top element, and finally sets the "next"
	pointer of the predecessor of the bottom element to NULL.
*/

void	ft_reverse_rotate_position(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*queue;
	t_stack	*before_queue;

	queue = get_bot_stack(*stack);
	before_queue = get_before_bot_stack(*stack);
	tmp = *stack;
	*stack = queue;
	(*stack)->next = tmp;
	before_queue->next = NULL;
}

void	ft_do_rra(t_stack **stack_a)
{
	ft_reverse_rotate_position(stack_a);
	ft_printf("rra\n");
}

void	ft_do_rrb(t_stack **stack_b)
{
	ft_reverse_rotate_position(stack_b);
	ft_printf("rrb\n");
}

void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_position(stack_a);
	ft_reverse_rotate_position(stack_b);
	ft_printf("rrr\n");
}
