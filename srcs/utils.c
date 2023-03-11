/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:42:30 by amugnier          #+#    #+#             */
/*   Updated: 2023/03/10 10:57:45 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nb_compare(const char *s1, const char *s2)
{
	long long	nb_i;
	long long	nb_j;

	nb_i = ft_atoi(s1);
	nb_j = ft_atoi(s2);
	if (nb_i == nb_j)
		return (0);
	else
		return (1);
}

int	ft_multiple_nb(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j] != NULL)
		{
			if (j != i && ft_nb_compare(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_args_nb(char *argv)
{
	int			i;
	long long	nb;

	nb = ft_atoi(argv);
	if (ft_strlen(argv) > 11)
		return (0);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	i = 0;
	if (ft_is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]) == 1)
		i++;
	if (argv[i] != '\0' && ft_isdigit(argv[i]) == 0)
		return (0);
	return (1);
}

int	ft_args_equal_zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;
	int	nb_of_zero;

	i = 1;
	nb_of_zero = 0;
	while (argv[i] != NULL)
	{
		if (ft_args_nb(argv[i]) == 0)
			return (0);
		nb_of_zero += ft_args_equal_zero(argv[i]);
		i++;
	}
	if (nb_of_zero > 1)
		return (0);
	if (ft_multiple_nb(argv))
		return (0);
	return (1);
}
