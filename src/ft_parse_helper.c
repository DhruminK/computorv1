/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:19:29 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 19:33:11 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static int	ft_parse_frac(double *coff, char **inp, uint8_t is_minus)
{
	double	s;
	char	*str;

	if (!coff || !inp || !*inp)
		return (-1);
	s = 10;
	str = *inp - 1;
	while (++str && *str && ft_is_valid(*(str)) == 3)
	{
		*coff = (*coff) + ((str[0] - '0') / s);
		s *= 10;
	}
	*inp = str;
	if (is_minus)
		*coff *= -1;
	return (0);
}

int	ft_parse_num(double *coff, char **inp)
{
	char	*s;
	uint8_t	is_minus;

	if (!coff || !inp || !*inp)
		return (-1);
	is_minus = 0;
	if ((*inp)[0] == '+')
		(*inp) += 1;
	else if ((*inp)[0] == '-' && (*inp)++)
		is_minus = 1;
	ft_skipspaces(inp);
	*coff = 0;
	s = *inp - 1;
	while (s && ft_is_valid(*(++s)) == 3)
		*coff = ((*coff) * 10) + (s[0] - '0');
	if (*coff != 0.0 && *s != '.' && is_minus && !(--is_minus))
		*coff *= -1;
	*inp = s;
	if (*s != '.')
		return (0);
	(*inp) = (*inp) + 1;
	return (ft_parse_frac(coff, inp, is_minus));
}

int	ft_read_inp_move(char **inp)
{
	int	ret;

	if (!inp)
		return (-1);
	ft_skipspaces(inp);
	ret = ft_is_valid((*inp)[0]);
	*inp += 1;
	return (ret);
}

static int	ft_parse_variable(double *pow, char **inp)
{
	int		ret;

	if (!pow || !inp || !*inp)
		return (-1);
	if (!((*inp)[0]))
		return (0);
	ret = ft_read_inp_move(inp);
	*pow = 0;
	if (ret == 4 || ret == 5 || ret == 7)
		return (1);
	if (ret == 6)
		ret = ft_read_inp_move(inp);
	if (ret != 1)
		return (-1);
	*pow = 1;
	ret = ft_read_inp_move(inp);
	if (ret == 4 || ret == 5 || ret == 7)
		return (1);
	if (ret != 8)
		return (-1);
	return (2);
}

int	ft_parse_single_coff(double *coff, double *pow, char **inp)
{
	int	ret;

	if (!coff || !pow || !inp)
		return (-1);
	*coff = 0;
	*pow = 0;
	ft_skipspaces(inp);
	if (ft_parse_num(coff, inp) == -1)
		return (-1);
	ret = ft_parse_variable(pow, inp);
	if (ret < 2)
		return (ret);
	if (ret == 1)
		*inp -= 1;
	if (ft_parse_num(pow, inp) == -1)
		return (-1);
	if ((*pow - ((int64_t)(*pow))) != 0.0)
		return (-2);
	if (*pow < 0)
		return (-3);
	return (0);
}
