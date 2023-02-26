/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:04:43 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:41:35 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_get_lowest_pos_index(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_position;

	tmp = *stack;
	lowest_index = INT_MAX;
	ft_get_position(stack);
	lowest_position = tmp->position;
	while (tmp != NULL)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_position);
}

int	ft_get_targ(t_stack **stack_a, int index_b,
	int index_target, int pos_target)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a != NULL)
	{
		if (tmp_a->index > index_b && tmp_a->index < index_target)
		{
			index_target = tmp_a->index;
			pos_target = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (index_target != INT_MAX)
		return (pos_target);
	tmp_a = *stack_a;
	while (tmp_a != NULL)
	{
		if (tmp_a->index < index_target)
		{
			index_target = tmp_a->index;
			pos_target = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (pos_target);
}

void	ft_get_targ_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		pos_target;

	tmp_b = *b;
	ft_get_position(a);
	ft_get_position(b);
	pos_target = 0;
	while (tmp_b != NULL)
	{
		pos_target = ft_get_targ(a, tmp_b->index, INT_MAX, pos_target);
		tmp_b->targ_pos = pos_target;
		tmp_b = tmp_b->next;
	}
}
