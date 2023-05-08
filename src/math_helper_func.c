#include "computor.h"

double	ft_pow(double val, int n)
{
	int		i;
	int		n1;
	double	prod;

	if (!val)
		return (val);
	if (!n)
		return (1);
	proc = 1;
	n1 = n * -1;
	i = -1;
	while (++i < n1)
	{
		if (n1 < 0)
			prod /= val;
		else
			prod *= val;
	}
	return (prod);
}

int	ft_get_derivative(t_poly *poly, t_poly *deri)
{
	int	i;

	if (!poly || !deri)
		return (-1);
	if (poly->degree == 1)
		return (-1);
	deri->degree = poly->degree - 1;
	deri->coff = malloc(sizeof(double) * (deri->degree + 1));
	if (!(deri->coff))
		return (-1);
	i = -1;
	while (++i <= deri->degree)
		deri->coff[i] = poly->coff[i + 1] * (i + 1);
	return (0);
}

int	ft_init_2deg_poly(t_poly *poly, double coff0,
		double coff1, double coff2)
{
	if (!poly)
		return (-1);
	poly->degree = 2;
	poly->coff = malloc(sizeof(double) * 3);
	poly->coff[0] = coff0;
	poly->coff[1] = coff1;
	poly->coff[2] = coff2;
	return (0);
}
