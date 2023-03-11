/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:16:46 by amugnier          #+#    #+#             */
/*   Updated: 2023/03/10 11:33:39 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Rotates a stack by moving the top element to the bottom. If the stack is
	empty or only contains one element, nothing happens. It first stores a
	pointer to the second element of the stack, sets the "next" pointer of the
	top element to NULL, then finds the last element of the stack and sets its
	"next" pointer to the top element. Finally, it sets the stack to the
	stored pointer to the second element.
*/

void	ft_rotate_position(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*queue;

	tmp = *stack;
	*stack = (*stack)->next;
	queue = get_bot_stack(*stack);
	tmp->next = NULL;
	queue->next = tmp;
}

void	ft_do_ra(t_stack **stack_a)
{
	ft_rotate_position(stack_a);
	ft_printf("ra\n");
}

void	ft_do_rb(t_stack **stack_b)
{
	ft_rotate_position(stack_b);
	ft_printf("rb\n");
}

void	ft_do_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_position(stack_a);
	ft_rotate_position(stack_b);
	ft_printf("rr\n");
}
