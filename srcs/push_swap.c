/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:05:21 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:36:27 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size_stack)
{
	if (size_stack == 2 && !ft_is_sorted(*stack_a))
		ft_do_sa(stack_a);
	else if (size_stack == 3)
		ft_tiny_stack_algo(stack_a);
	else if (size_stack > 3 && !ft_is_sorted(*stack_a))
		ft_algo(stack_a, stack_b);
}
