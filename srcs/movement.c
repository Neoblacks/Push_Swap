/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:59:42 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:41:06 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_do_rev_rotate_both_position(t_stack **stack_a, t_stack **stack_b,
	int *count_a, int *count_b)
{
	while (*count_a < 0 && *count_b < 0)
	{
		(*count_a)++;
		(*count_b)++;
		ft_do_rrr(stack_a, stack_b);
	}
}

void	ft_do_rotate_both_position(t_stack **stack_a, t_stack **stack_b,
	int *count_a, int *count_b)
{
	while (*count_a > 0 && *count_b > 0)
	{
		(*count_a)--;
		(*count_b)--;
		ft_do_rr(stack_a, stack_b);
	}
}

void	ft_do_rotate_stack_a(t_stack **stack_a, int *count)
{
	while (*count)
	{
		if (*count > 0)
		{
			ft_do_ra(stack_a);
			(*count)--;
		}
		else if (*count < 0)
		{
			ft_do_rra(stack_a);
			(*count)++;
		}
	}
}

void	ft_do_rotate_stack_b(t_stack **stack_b, int *count)
{
	while (*count)
	{
		if (*count > 0)
		{
			ft_do_rb(stack_b);
			(*count)--;
		}
		else if (*count < 0)
		{
			ft_do_rrb(stack_b);
			(*count)++;
		}
	}
}

void	ft_do_move(t_stack **stack_a, t_stack **stack_b,
	int count_a, int count_b)
{
	if (count_a < 0 && count_b < 0)
		ft_do_rev_rotate_both_position(stack_a, stack_b, &count_a, &count_b);
	else if (count_a > 0 && count_b > 0)
		ft_do_rotate_both_position(stack_a, stack_b, &count_a, &count_b);
	ft_do_rotate_stack_a(stack_a, &count_a);
	ft_do_rotate_stack_b(stack_b, &count_b);
	ft_do_pa(stack_a, stack_b);
}
