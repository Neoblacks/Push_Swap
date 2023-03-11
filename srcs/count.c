/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:36 by amugnier          #+#    #+#             */
/*   Updated: 2023/03/10 11:10:48 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Calculates the "count" values for the elements of stack_b.
	These values are used to determine the best moves to make in
	the sorting algorithm. It calculates the number of moves needed to move
	an element from its current position to the top of stack_a and the number
	of moves needed to move an element from its current position to its target
	position on stack_a. It then stores these values in the "count_a" and
	"count_b" fields of each element in stack_b.
*/

void	ft_get_count(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_get_size_stack(tmp_a);
	size_b = ft_get_size_stack(tmp_b);
	while (tmp_b != NULL)
	{
		tmp_b->count_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->count_b = (size_b - tmp_b->position) * -1;
		tmp_b->count_a = tmp_b->targ_pos;
		if (tmp_b->targ_pos > size_a / 2)
			tmp_b->count_a = (size_a - tmp_b->targ_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_do_not_much_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		not_much;
	int		count_a;
	int		count_b;

	tmp = *stack_b;
	not_much = INT_MAX;
	while (tmp != NULL)
	{
		if (nb_abs(tmp->count_a) + nb_abs(tmp->count_b) < nb_abs(not_much))
		{
			not_much = nb_abs(tmp->count_a) + nb_abs(tmp->count_b);
			count_a = tmp->count_a;
			count_b = tmp->count_b;
		}
		tmp = tmp->next;
	}
	ft_do_move(stack_a, stack_b, count_a, count_b);
}
