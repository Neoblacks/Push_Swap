/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:26:38 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/26 11:46:16 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				targ_pos;
	int				index;
	int				count_a;
	int				count_b;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_init_stack(int argc, char **argv);
t_stack	*get_bot_stack(t_stack *stack);
t_stack	*get_before_bot_stack(t_stack *stack);
t_stack	*create_new_stack(int value);
void	add_stack_bot(t_stack **stack, t_stack *new);

void	ft_swap_position(t_stack *stack);
void	ft_do_sa(t_stack **stack_a);
void	ft_do_sb(t_stack **stack_b);
void	ft_do_ss(t_stack **stack_a, t_stack **stack_b);

void	ft_push_stack(t_stack **src, t_stack **dest);
void	ft_do_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_do_pb(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate_position(t_stack **stack);
void	ft_do_ra(t_stack **stack_a);
void	ft_do_rb(t_stack **stack_b);
void	ft_do_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_reverse_rotate_position(t_stack **stack);
void	ft_do_rra(t_stack **stack_a);
void	ft_do_rrb(t_stack **stack_b);
void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_get_size_stack(t_stack *stack);
void	ft_assign_index(t_stack *stack_a, int size_stack);
void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size_stack);
int		ft_is_sorted(t_stack *stack);
void	ft_push_all_save_three(t_stack **stack_a, t_stack **stack_b);
void	ft_algo(t_stack **stack_a, t_stack **stack_b);
int		ft_get_highest(t_stack *stack);
void	ft_tiny_stack_algo(t_stack **stack);
void	ft_get_position(t_stack **stack);
int		ft_get_lowest_pos_index(t_stack **stack);
void	shifting_stack(t_stack **stack_a);
int		ft_get_targ(t_stack **a, int index_b, int index_target, int pos_target);
void	ft_get_targ_pos(t_stack **a, t_stack **b);
void	ft_get_count(t_stack **stack_a, t_stack **stack_b);
void	ft_do_not_much_move(t_stack **stack_a, t_stack **stack_b);
int		nb_abs(int nb);
void	ft_get_count(t_stack **stack_a, t_stack **stack_b);
void	ft_do_rev_rotate_both_position(t_stack **stack_a,
			t_stack **stack_b, int *count_a, int *count_b);
void	ft_do_rotate_stack_a(t_stack **stack_b, int *count);
void	ft_do_rotate_stack_b(t_stack **stack_b, int *count);
void	ft_do_move(t_stack **stack_a, t_stack **stack_b,
			int count_a, int count_b);
void	ft_free_stack(t_stack **stack);
int		ft_nb_compare(const char *s1, const char *s2);
int		ft_multiple_nb(char **argv);
int		ft_args_nb(char *argv);
int		ft_args_equal_zero(char *argv);
int		ft_check_args(char **argv);

int		main(int argc, char **argv);
#endif
