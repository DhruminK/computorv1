#include "computor.h"

void	ft_solve_linear(t_poly *eqn)
{
	if (!eqn)
		return ;
	printf("The solution is:\n");
	printf("%.6f\n", -1 * (eqn->coff[0]) / (eqn->coff[1]));
}

void	ft_solve_quad(t_poly *eqn)
{
	double	des;
	double	half_soln;

	if (!eqn)
		return ;
	des = (eqn->coff[1] * eqn->coff[1]) - (4 * eqn->coff[0] * eqn->coff[2]);
	half_soln = (-(eqn->coff[1])) / (2 * (eqn->coff[2]));
	if (det == 0)
	{
		printf("Discriminant is zero, the single solution is :\n");
		printf("%.6f\n", half_soln);
		return ;
	}
	printf("Discriminant is strictly positive, the two solutions are:\n");
	printf("%.6\n", half_soln - (ft_sqrt(des) / (2 * eqn->coff[2])));
	printf("%.6\n", half_soln + (ft_sqrt(des) / (2 * eqn->coff[2])));
}

void	ft_outlier_soln(t_poly *eqn)
{
	if (!eqn)
		return ;
	if (eqn->coff[0] != 0 && eqn->coff[1] == 0 && eqn->coff[2] == 0)
		printf("This polynomial has no solutions\n");
	if (eqn->coff[0] == 0 && eqn->coff[1] == 0 && eqn->coff[2] == 0)
		printf("This polynomial has infinite solutions\n");
}

void	ft_solve(t_poly *eqn)
{
	if (!eqn)
		return ;
	if (eqn->coff[1] == 0 && eqn->coff[2] == 0)
		return (ft_outlier_soln(eqn));
	if (eqn->degree == 1)
		return (ft_solve_linear(eqn));
	return (ft_solve_quad(eqn));
}
