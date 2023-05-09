/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:08:50 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 18:55:51 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include <string.h>

# define MAX_ITERATIONS	8

typedef struct t_poly
{
	uint8_t		degree;
	double		*coff;
}				t_poly;

double			ft_pow(double val, int n);
int				ft_get_derivative(t_poly *poly, t_poly *deri);
int				ft_init_2deg_poly(t_poly *poly, double coff0,
					double coff1, double coff2);
double			ft_sqrt(double num);

void			ft_skip_whitespaces(char **inp);
void			ft_solve(t_poly *eqn);
int				ft_check_degree_valid(t_poly *eqn, int min_degree, int is_zero);

int				ft_parse_eqn(t_poly *poly, char *inp);
int				ft_parse_single_coff(double *coff, double *pow, char **inp);
int				ft_read_inp_move(char **inp);
int				ft_parse_num(double *coff, char **inp);

int				ft_check_degree_valid(t_poly *eqn, int min_degree, int is_zero);
int				ft_is_valid(char ch);
void			ft_skipspaces(char **inp);

#endif
