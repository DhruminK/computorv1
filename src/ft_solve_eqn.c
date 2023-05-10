/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_eqn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:06:45 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 17:06:46 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	ft_solve_linear(t_poly *eqn)
{
	if (!eqn)
		return ;
	printf("Polynomial degree: 1\n");
	printf("The solution is:\n");
	printf("%.6f\n", -1 * (eqn->coff[0]) / (eqn->coff[1]));
}

static void	ft_solve_quad_neg(double a, double des, double half_soln)
{
	double complex	z;
	double			sqrt;

	if (!a || des >= 0)
		return ;
	printf("Discriminant is strictly negative, the "
		"two complex solutions are:\n");
	sqrt = ft_sqrt(des * -1);
	z = half_soln - (I * (sqrt / 2 * a));
	printf("%f + I * %f\n", creal(z), cimag(z));
	z = half_soln + (I * (sqrt / 2 * a));
	printf("%f + I * %f\n", creal(z), cimag(z));
}

static void	ft_solve_quad(double a, double des, double half_soln)
{
	if (!a)
		return ;
	printf("Polynomial Degree : 2\n");
	if (des == 0)
	{
		printf("Discriminant is zero, the single solution is :\n");
		printf("%.6f\n", half_soln);
		return ;
	}
	if (des > 0)
	{
		printf("Discriminant is strictly positive, the two solutions are:\n");
		printf("%.6f\n", half_soln - (ft_sqrt(des) / (2 * a)));
		printf("%.6f\n", half_soln + (ft_sqrt(des) / (2 * a)));
		return ;
	}
	ft_solve_quad_neg(a, des, half_soln);
}

static void	ft_solve_outlier(t_poly *eqn)
{
	if (!eqn)
		return ;
	if (eqn->coff[0] != 0.0 && eqn->coff[1] == 0.0 && eqn->coff[2] == 0.0)
		printf("This polynomial has no solutions\n");
	if (eqn->coff[0] == 0.0 && eqn->coff[1] == 0.0 && eqn->coff[2] == 0.0)
		printf("This polynomial has infinite solutions\n");
}

void	ft_solve(t_poly *eqn)
{
	double	des;
	double	half_soln;

	if (!eqn)
		return ;
	if (ft_check_degree_valid(eqn, 0, 1) == 1)
		return (ft_solve_outlier(eqn));
	else if (ft_check_degree_valid(eqn, 1, 0) == 1)
		return (ft_solve_linear(eqn));
	else if (ft_check_degree_valid(eqn, 2, 0) == 1)
	{
		des = (eqn->coff[1] * eqn->coff[1]) - (4 * eqn->coff[0] * eqn->coff[2]);
		half_soln = (-1 * (eqn->coff[1])) / (2 * eqn->coff[2]);
		return (ft_solve_quad(eqn->coff[2], des, half_soln));
	}
	else if (eqn->degree > 2)
	{
		printf("Polynomial Degree : %d\n", eqn->degree);
		printf("The polynomial degree is strictly "
			"greater than 2, I can't solve.\n");
	}
}
