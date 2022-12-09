/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:43:48 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/19 20:53:56 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Main pour tester des libfts

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	test(int (*f)(int), int begin, int end, int success_value)
{
	int	val;
	int	res;

	val = begin;
	res = EXIT_SUCCESS;
	while (val <= end)
	{
		if (f(val) == 0)
			res = EXIT_FAILURE;
		val++;
	}
	if (res == !success_value)
		printf("[KO] ");
	else
		printf("[OK] ");
}

int	main(void)
{

	//test ft_isalpha
	printf("ft_isAlpha :\n");

	test(ft_isalpha, 'a', 'z', EXIT_SUCCESS);
	test(ft_isalpha, 'A', 'Z', EXIT_SUCCESS);
	test(ft_isalpha, 0, 64, EXIT_FAILURE);

	printf("\n\nft_isalnum : \n");
	test(ft_isalnum, '0', '9', EXIT_SUCCESS);
	test(ft_isalnum, 'a', 'z', EXIT_SUCCESS);
	test(ft_isalnum, 'A', 'Z', EXIT_SUCCESS);
	test(ft_isalnum, 0, 47, EXIT_FAILURE);

	printf("\n\nft_isdigit : \n");
	test(ft_isdigit, '0', '9', EXIT_SUCCESS);
	test(ft_isdigit, 'a', 'z', EXIT_FAILURE);
	test(ft_isdigit, 'A', 'Z', EXIT_FAILURE);
	test(ft_isdigit, 0, 47, EXIT_FAILURE);

	printf("\n\nft_isprint : \n");
	test(ft_isprint, 32, 126, EXIT_SUCCESS);
	test(ft_isprint, 0, 31, EXIT_FAILURE);

	printf("\n\nft_isascii : \n");
	test(ft_isprint, 0, 127, EXIT_SUCCESS); // soucis a check ?
	test(ft_isprint, 0 - 1, 127 + 1, EXIT_FAILURE);




/*
	uval = 'A';
	printf("\n");
	while (uval <= 'Z')
	{
		if (ft_isalpha(val) == 0)
		{
			printf("KO");
			gen_res = EXIT_FAILURE;
		}
		(ft_isalpha(uval) ? printf("%c.OK / ", uval) : printf("%c.KO / ",uval));
		uval++;
	}
	fval = 0;
	printf("\n");
	while (fval <= 64)
	{
		(ft_isalpha(uval) ? printf("KO / ") : printf("OK / "));
		fval++;
	}

	//test ft_isdigit
*/
	return (EXIT_SUCCESS);
}
