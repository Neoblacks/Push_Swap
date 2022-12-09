/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:26:38 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/09 11:41:00 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
}				t_stack;

typedef struct s_start
{
	struct s_stack	*ba;
	struct s_stack	*bb;
	struct s_stack	*inst;
}				t_start;


#endif
