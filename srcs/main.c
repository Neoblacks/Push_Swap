/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:52:52 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/08 19:40:15 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_stack *stack_a;
	t_stack *stack_b;
	int	size_stack;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = ft_init_stack(argc, argv); // Create a stack with the arguments
	size_stack = ft_get_size_stack(stack_a); // Get the size of the stack
	ft_assign_index(stack_a, size_stack + 1); // Assign an index to each element of the stack
	ft_push_swap(&stack_a, &stack_b, size_stack); // Sort the stack
}
