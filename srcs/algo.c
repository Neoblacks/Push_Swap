/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:51:18 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/08 20:24:19 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int		size_stack;
	int		i;
	int		pushed;

	size_stack = ft_get_size_stack(*stack_a);
	pushed = 0;
	i = 0;
	while (size_stack > 6 && i < size_stack && pushed < size_stack / 2)
	{
		if ((*stack_a)->index <= size_stack / 2)
		{
			ft_do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_do_ra(stack_a);
		i++;
	}
	while (size_stack - pushed > 3)
	{
		ft_do_pb(stack_a, stack_b);
		pushed++;
	}
}

int	ft_get_highest(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack != NULL)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	ft_tiny_stack_algo(t_stack **stack)
{
	int	highest;

	if (ft_is_sorted(*stack))
		return ;
	highest = ft_get_highest(*stack);
	if ((*stack)->index == highest)
		ft_do_ra(stack);
	else if ((*stack)->next->index == highest)
	{
		ft_do_rra(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
		ft_do_sa(stack);
}

void	shifting_stack(t_stack **stack_a)
{
	int		size_stack;
	int		lowest_position;

	size_stack = ft_get_size_stack(*stack_a);
	lowest_position = ft_get_lowest_pos_index(stack_a);
	if (lowest_position > size_stack / 2)
	{
		while (lowest_position < size_stack)
		{
			ft_do_rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			ft_do_ra(stack_a);
			lowest_position--;
		}
	}
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_all_save_three(stack_a, stack_b);
	ft_tiny_stack_algo(stack_a);
	while (*stack_b)
	{
		ft_get_targ_pos(stack_a, stack_b);
		ft_get_count(stack_a, stack_b);
		ft_do_not_much_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		shifting_stack(stack_a);
}
