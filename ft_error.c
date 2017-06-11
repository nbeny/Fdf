#include "fdf.h"

t_env			*ft_error_gnl(t_env *e, int err, char *file)
{
	struct stat		sta;

	stat(file, &sta);
	e->error = 0;
	if (S_ISDIR(sta.st_mode) == 1)
	{
		e->error = 1;
		ft_putendl("Please give me a map not a directory");
		return (e);
	}
	if (err < 1)
	{
		e->error = 1;
		ft_putendl("Please give me some valid arguments");
		return (e);
	}
	return (e);
}

void			ft_color_min_end(t_env *e, t_color c)
{
	if (c.z_min == e->min)
		c.color_min = 1;
	if (c.color - abs(c.color_min) != 0 && c.ite_max != 0 &&\
			(255 / c.ite_max <= 1))
	{
		c.nb_pix = (int)((c.ite_max / (c.color - abs(c.color_min))));
		c.pass = 1;
	}
	else if (c.color - abs(c.color_min) != 0 && c.ite_max != 0 &&\
			(255 / c.ite_max >= 1))
	{
		c.nb_pix = 1;
		c.pass = (abs(c.color - c.color_min) / c.ite_max);
	}
	else
		c.nb_pix = 0;
}
