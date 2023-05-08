#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_ITERATIONS	8

typedef struct t_poly
{
	uint8_t		degree;
	double		*coff;
} 				t_poly;

double			ft_pow(double val, int n);
int				ft_get_derivative(t_poly *poly, t_poly *deri);
int				ft_init_2deg_poly(t_poly *poly, double coff0,
					double coff1, double coff2);
double			ft_sqrt(double num);

void			ft_skip_whitespaces(char **inp);

#endif
