/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:15:10 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/09 13:17:05 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_start	*ft_init_start(void)
{
	t_start	*start;

	start = (t_start *)malloc(sizeof(t_start));
	if (!start)
		return (0);
	ft_bzero(start, sizeof(t_start));
	return (start);
}

static char	*ft_find_numb(char *str, int j)
{
	int	i;
	int	k;
	char *str;

	i = 0;
	k = j;

	while (str[j] != ' ' && str[j] != '\0')
	{
		j++;
		k++;
	}
	while (((str[j] > 47 && str[j] < 58) || str[j] == 43 || str[j] == 45)
			&& str[j] != '\0')
	{
		j++;
		i++;
	}
	str = ft_substr(str, k, i);
	return (str);
}

static int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i] != '\0')
			i++;
		else if (((str[i] < '0' || str[i] > '9') || str[i] == 43 || str[i] == 45)
			&& (i = 0 || str[i- 1] == ' ') && str[i] != '\0')
		{
			i++;
			count++;
		}
		else if (str[i] < '0' || str[i] > '9' && str[i] != 32)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else if (str[i] > 47 && str[i] < 58 && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_next_nb(char *str, int j)
{
	while (str[j] != ' ' && str[j] != '\0')
		j++;
	while (str[j] > 47 && str[j] < 58 && str[j] == 43 || str[j] == 45
			&& str[j] != '\0')
		j++;
	return (j);
}

static int	*ft_fill(char *str, int nb)
{
	int	*tab;
	int	i;
	char *str;
	int	j;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int) * nb);
	if (!tab)
		return (0);
	while (i < nb)
	{
		str = ft_find_numb(str, j);
		j = ft_next_nb(str, j);
		tab[i] = ft_atoi(str); // maybe double free
		free(str); // maybe double free
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_start	*start;

	start = ft_init_start();
	start->bb = NULL;
	start->inst = NULL;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
		t_stack *ea;
		t_stack *ba;
		int		number;
		int		i;
		char	*tab;

		ea = NULL;
		ba = NULL;
		i = ft_count_words(argv);
		if (i == 0)
			exit(0);

	return (0);
}
