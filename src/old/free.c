#include "fdf.h"

void	ft_free_tabstr(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		if (tab[i] != NULL)
			while (tab[i] != NULL)
			{
				ft_strdel(&tab[i]);
				tab[i] = NULL;
				i++;
			}
		free(tab);
		tab = NULL;
	}
}
