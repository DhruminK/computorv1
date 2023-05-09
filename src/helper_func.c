/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:04:45 by dkhatri           #+#    #+#             */
/*   Updated: 2023/05/09 18:06:05 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int	ft_check_degree_valid(t_poly *eqn, int min_degree, int is_zero)
{
	int	i;

	if (!eqn || eqn->degree < min_degree
		|| (!is_zero && eqn->coff[min_degree] == 0.0))
		return (0);
	if (eqn->degree == min_degree)
		return (1);
	i = min_degree;
	while (++i <= eqn->degree)
	{
		if (eqn->coff[i] != 0.0)
			return (0);
	}
	return (1);
}

int	ft_is_valid(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	else if (ch >= 'a' && ch <= 'z')
		return (2);
	else if (ch >= '0' && ch <= '9')
		return (3);
	else if (ch == '+')
		return (4);
	else if (ch == '-')
		return (5);
	else if (ch == '*')
		return (6);
	else if (ch == '=')
		return (7);
	else if (ch == '^')
		return (8);
	return (0);
}

void	ft_skipspaces(char **inp)
{
	char	*s;

	if (!inp)
		return ;
	s = *inp;
	while (s && *s && (*s == ' ' || (*s >= 9 && *s <= 13)))
		s += 1;
	*inp = s;
}
