/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:20:39 by amugnier          #+#    #+#             */
/*   Updated: 2023/03/10 11:07:10 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Returns the last element of a stack. It traverses the stack
	until it reaches the last element and returns a pointer to it
*/

t_stack	*get_bot_stack(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*
	Returns the second-to-last element of a stack. It traverses the stack until
	it reaches the element just before the last element and
	returns a pointer to it.
*/

t_stack	*get_before_bot_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*create_new_stack(int value)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof * new_stack);
	if (new_stack == NULL)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->position = -1;
	new_stack->targ_pos = -1;
	new_stack->count_a = -1;
	new_stack->count_b = -1;
	new_stack->next = NULL;
	return (new_stack);
}

/*
	Adds a new element to the bottom of a stack. If the stack is empty, it
	creates a new stack with the element, otherwise it finds the current last
	element of the stack and sets its "next" pointer to the new element.
*/

void	add_stack_bot(t_stack **stack, t_stack *new)
{
	t_stack	*queue;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	queue = get_bot_stack(*stack);
	queue->next = new;
}

int	ft_get_size_stack(t_stack *stack)
{
	int	size_stack;

	size_stack = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size_stack++;
	}
	return (size_stack);
}
