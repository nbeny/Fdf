#include "../include/libft.h"

int		ft_whiledigit(char *str)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			neg = 1;
		else if (str[i] == '-' && neg == 1)
		{
			i++;
			neg = 0;
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
