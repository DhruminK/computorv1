/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:28:02 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 19:41:50 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int ft_return_err(uint8_t err)
{
	if (err == 1)
		printf("Number of arguements not equal to 1\n");
	else if (err == 2)
		printf("Unable to allocate memory");
	else if (err == 3)
		printf("Power of one of the variables is negative\n");
	else if (err == 4)
		printf("Power of one of the variables is fractional\n");
	else if (err == 5)
		printf("Encountered error while parsing\n");
	return (1);
}

static void	ft_print_single_coff(double coff, int index)
{
	char	op;

	if (!coff)
		return ;
	op = '+';
	if (coff < 0)
	{
		op = '-';
		coff *= -1;
	}
	if (op == '-' || index != 0)
		printf("%c", op);
	if (index != 0)
		printf(" ");
	printf("%.1f * X^%d ", coff, index);
}

static void	ft_print_reduce_form(t_poly *poly)
{
	int		i;

	if (!poly)
		return ;
	i = -1;
	while (++i <= poly->degree)
		ft_print_single_coff(poly->coff[i], i);
	printf("= 0\n");
}

int	main(int ac, char **av)
{
	t_poly	eqn;
	int		ret;

	if (ac != 2)
		return (ft_return_err(1));
	if (ft_init_2deg_poly(&eqn, 0, 0, 0) == -1)
		return (ft_return_err(2));
	ret = ft_parse_eqn(&eqn, av[1]);
	if (ret == -1)
		return (ft_return_err(5));
	else if (ret == -2)
		return (ft_return_err(4));
	else if (ret == -3)
		return (ft_return_err(3));
	ft_print_reduce_form(&eqn);
	printf("Polynomial degree: %d\n", eqn.degree);
	ft_solve(&eqn);
	if (eqn.coff)
		free(eqn.coff);
	return (0);
}
