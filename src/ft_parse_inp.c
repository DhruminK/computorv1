#include "computor.h"

static int	ft_parse_frac(double *coff, char **inp)
{
	int		i;
	char	*s;

	if (!coff || !inp)
		return (-1);
	s = *inp;
	i = 0;
	while (++i && *s && *s >= '0' && *s <= '9')
		(*coff) = (*coff) + (((double)(inp[i] - '0'))
				/ pow(10, -1 * (i + 1)));
	*inp = s;
	return (0);
}

static int	ft_parse_num(double *coff, char **inp)
{
	char	*s;
	int8_t	minus;
	int		ret;

	if (!coff || !inp || !*inp)
		return (-1);
	ft_skip_whitespaces(inp);
	if (s[0] == 'X')
		*coff = 1;
	s = *inp;
	if (ft_is_validchar(s[0]) != 0 || s[0] == '=' || s[0] == 'X')
		return (0);
	minus = 1;
	if (ft_is_op(s[0]) == 1 && (s++) && *(s - 1) == '-')
		minus = -1;
	while (*s && *s >= '0' && *s <= '9')
		(*coff) = (*coff * 10) + (*(s++) - '0');
	*inp = s;
	if (*inp[0] == '.' && ((*inp)++) && ft_parse_frac(coff, inp) == -1)
		return (-1);
	*coff *= minus;
	return (0);
}

static int	ft_parse_single_coff(double *coff, double *pow, char **inp)
{
	if (!coff || !pow || !inp)
		return (-1);
	if (ft_parse_num(coff, inp) == -1)
		return (-1);
	ft_skip_whitespaces(inp);
	*pow = 0;
	if ((*inp)[0] != 'X' || (*inp)[0] != '*')
		return (0);
	if ((*inp)[0] == 'X' && ((*inp)++))
		ft_skip_whitespaces(inp);
	if ((*inp)[0] == '*' && ((*inp)++))
		ft_skip_whitespaces(inp);
	if (ft_parse_num(pow, inp) == -1)
		return (-1);
	return (0);
}

static void	ft_parse_find_coff(double coff, double pow, t_poly *p)
{
	double	*n_ptr;

	if (pow >= 0 && pow <= 2)
	{
		p->coff[pow] += coff;
		return ;
	}

	if (pow >= 2)
	{
		n_ptr = realloc(p->coff, sizeof(double) * (pow + 1));
		if (!n_ptr)
			return ;
		p->coff = n_ptr;
		p->coff[pow] = coff;
		ft_memset(p->coff + p->degree + 1, 0
				, sizeof(double) * (pow - p->degree));
		p->degree = pow;
	}
}

int	ft_parse_eqn(char *inp, t_poly *eqn)
{
	uint8_t	b;
	double	coff;
	double	pow;

	if (!inp || !eqn)
		return (-1);
	b = 0;
	while (inp[0])
	{
		ft_skip_whitespaces(&inp);
		if (inp[0] == '=' && b == 0)
			return (-1);
		if (inp[0] == '=')
			inp += 1;
		if (ft_parse_single_coff(&coff, &pow, &inp) == -1)
			return (-1);
		if (pow < 0)
			return (-2);
		ft_parse_find_coff(coff, pow, eqn);
		b = 1;
	}
	return (0);
}
