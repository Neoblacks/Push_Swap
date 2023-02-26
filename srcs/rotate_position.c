/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:16:46 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:35:44 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
