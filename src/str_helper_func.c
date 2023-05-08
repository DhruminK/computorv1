#include "computor.h"

void	ft_skip_whitespaces(char **inp)
{
	char	*s;

	if (!inp)
		return ;
	s = *inp;
	while (*s && ((*s >= 9 && *s <= 13) || *s == ' '))
		*s += 1;
	*inp = s;
}

int	ft_is_op(char inp)
{
	if (inp == '+' || inp == '-' || inp == '*')
		return (1);
	return (0);
}

int	ft_is_validchar(char inp)
{
	if (inp >= '0' && inp <= '9')
		return (1);
	if (ft_is_op(inp) || inp == '=')
		return (1);
	return (inp == 'X');
}
