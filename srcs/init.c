/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:30:58 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/20 14:37:29 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	number;
	int			i;

	stack_a = NULL;
	number = 0;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			ft_printf("Error INT MAX OU INT MIN DEPASSE\n");
		if (i == 1)
			stack_a = create_new_stack(number);
		else
			add_stack_bot(&stack_a, create_new_stack(number));
		i++;
	}
	return (stack_a);
}

void	ft_assign_index(t_stack *stack_a, int size_stack)
{
	t_stack	*pointer;
	t_stack	*highest;
	int		i;

	while (--size_stack > 0)
	{
		pointer = stack_a;
		highest = NULL;
		i = INT_MIN;
		while (pointer)
		{
			if (pointer->value == INT_MIN && pointer->index == 0)
				pointer->index = 1;
			if (pointer->value > i && pointer->index == 0)
			{
				i = pointer->value;
				highest = pointer;
				pointer = stack_a;
			}
			else
				pointer = pointer->next;
		}
		if (highest != NULL)
			highest->index = size_stack;
	}
}
