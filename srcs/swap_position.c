/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:12:03 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:36:24 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_position(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	ft_do_sa(t_stack **stack_a)
{
	ft_swap_position(*stack_a);
	ft_printf("sa\n");
}

void	ft_do_sb(t_stack **stack_b)
{
	ft_swap_position(*stack_b);
	ft_printf("sb\n");
}

void	ft_do_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_position(*stack_a);
	ft_swap_position(*stack_b);
	ft_printf("ss\n");
}
