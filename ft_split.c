#include "libft.h"

int				nb_str(char *str)
{
	int			nb;
	int			i;
	int			c;

	c = 0;
	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 9 && str[i] != 32 && c == 0)
		{
			nb++;
			i++;
			c = 2;
		}
		if ((str[i] == 9 || str[i] == 32) && c == 2)
			c = 0;
		i++;
	}
	return (nb);
}

int				pos_str(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == 9 || str[i] == 32)
			i++;
		else
			return (i);
	}
	return (i);
}

int				length(char *str, int i)
{
	int			length;

	length = i;
	while (str[length] != 9 && str[length] != 32 && str[length] != '\0')
		length++;
	return (length - i);
}

char			*new_str(char *str, int i, int length)
{
	char		*new_str;
	int			j;

	j = 0;
	if (!(new_str = (char *)malloc(sizeof(char) * length + 1)))
		return (NULL);
	while (j != length && str[i] != '\0')
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	return (new_str);
}

char			**ft_split(char *str)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * nb_str(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		i = pos_str(str, i);
		tab[j] = new_str(str, i, length(str, i));
		j++;
		i = i + length(str, i);
	}
	tab[j] = NULL;
	return (tab);
}
