/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:14:46 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:39:47 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	ft_do_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_do_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
