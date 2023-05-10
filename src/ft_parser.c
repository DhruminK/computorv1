/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:13:47 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 19:42:43 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	ft_process_single_coff(t_poly *poly, double coff,
				double pow, int pass_eq)
{
	void	*tmp;

	if (!poly)
		return (-1);

	if ((int)pow <= poly->degree)
	{
		poly->coff[(int)pow] += (pass_eq * (coff));
		return (0);
	}
	tmp = realloc(poly->coff, sizeof(double) * (pow + 1));
	if (!tmp)
		return (0);
	poly->coff = tmp;
	memset(poly->coff + poly->degree + 1, 0,
			sizeof(double) * (pow - poly->degree));
	poly->degree = pow;
	poly->coff[(int)pow] += (pass_eq * (coff));
	return (0);
}

int	ft_parse_eqn(t_poly *poly, char *inp)
{
	double	coff;
	double	pow;
	int		ret;
	int		pass_eq;

	if (!poly || !inp)
		return (-1);
	pass_eq = 1;
	while (inp && *inp)
	{
		ft_skipspaces(&inp);
		if (ft_is_valid(*inp) == 7 && (inp++))
			pass_eq = -1;
		ret = ft_parse_single_coff(&coff, &pow, &inp);
		if (ret < 0)
			return (ret);
		if (coff && ft_process_single_coff(poly, coff, pow, pass_eq) == -1)
			return (ret);
	}
	if (pass_eq != -1)
		return (-1);
	return (0);
}
