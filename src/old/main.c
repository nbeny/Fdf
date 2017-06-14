#include "fdf.h"

t_coor	*ft_init_coor(char **av)
{
	t_coor	*c;

	if (!(c = (t_coor *)malloc(sizeof(t_coor))))
		return (NULL);
	c->mlx = mlx_init();
	c->win = mlx_new_window(c->mlx, WIN_X, WIN_Y, "mlx 42");
	c->j = 1;
	c->x = START_X;
	c->y = START_Y;
	c->z = 0;
	c->fd = open(av[1], O_RDONLY);
	c->powa = NULL;
	return (c);
}

void	ft_trace_line_x(int xi,int yi,int xf,int yf)
{
	int	dx;
	int	dy;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	mlx_pixel_put(c->mlx, c->win, x, y, 0xFFFFFF);
	cumul = dx / 2;
	x = xi + 1;
	while (x++ <= xf)
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y += 1;
		}
		mlx_pixel_put(c->mlx, c->win, x, y, 0xFFFFFF);
	}
}

void	ft_trace_line_y(int xi,int yi,int xf,int yf)
{
	int dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	allume_pixel(x,y);
	if ( dx > dy )
	{
		cumul = dx / 2;
		i = 1;
		while (i++ <= dx)
		{
			x += xinc;
			cumul += dy;
			if ( cumul >= dx )
			{
				cumul -= dx;
				y += yinc;
			}
			allume_pixel(x,y);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i++ <= dy)
		{
			y += yinc;
			cumul += dx;
			if ( cumul >= dy )
			{
				cumul -= dy;
				x += xinc;
			}
			allume_pixel(x,y);
		}
	}
}

void	ft_trace_x(t_coor *c)
{
	int	x;
	int	y;

	x = c->x - PIX;
	y = c->y - PIX;
	while (x != c->x && y != c->y)
	{
		x++;
		y++;
		mlx_pixel_put(c->mlx, c->win, x, y, 0xFFFFFF);
	}
}

void	ft_trace_y(t_coor *c)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = c->x - (c->j * PIX_X);
	y = c->y - (c->j * PIX_Y) / 2;
	i = c->x;
	j = c->y;
	while (i != x && j != y)
	{
		i--;
		if (i % 2 == 0)
			j++;
		mlx_pixel_put(c->mlx, c->win, i, j, 0xFFFFFF);
	}
}

int		main(int ac, char **av)
{
	t_coor	*c;
	char	*line;
	int		x;
//	int		y;

	if (ac != 2)
	{
		ft_printf(2, "usage: ./fdf [path_map]\n");
		return (-1);
	}
	c = ft_init_coor(av);
	while (get_next_line(c->fd, &line) > 0)
	{
		c->i = 0;
		c->powa = ft_strsplit(line, ' ');
		while (c->powa[c->i++])
		{
//			x = 0.6 * c->x - 0.6 * c->y;
//			y = ft_atoi(c->powa[c->i]) * (0.6 / 2) * c->x;
			if (ft_atoi(c->powa[c->i]) != 0)
				x = c->x + ft_atoi(c->powa[c->i]);
			else
				x = c->x;
			mlx_pixel_put(c->mlx, c->win, x, c->y, 0xFFFFFF);
			ft_trace_y(c->x);
			c->x = c->x + PIX;
			c->y = c->y + PIX;
			ft_trace_x(c);
		}
		c->x = START_X - (c->j * PIX);
		c->y = START_Y + (c->j * PIX) / 2;
		c->j++;
		ft_free_tabstr(c->powa);
		ft_strdel(&line);
	}
	mlx_loop(c->mlx);
	return (0);
}

/*
**screen.x = (map.x - map.y) * TILE_WIDTH_HALF;
**screen.y = (map.x + map.y) * TILE_HEIGHT_HALF;
**https://gamedevelopment.tutsplus.com/tutorials/creating-isometric-worlds-a-primer-for-game-developers--gamedev-6511
**http://clintbellanger.net/articles/isometric_math/
*/

/*
  void ligne(int xi,int yi,int xf,int yf) {
  int dx,dy,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  allume_pixel(x,y) ;
  cumul = dx / 2 ;
  for ( x = xi+1 ; x <= xf ; x++ ) {
  cumul += dy ;
  if ( cumul >= dx ) {
  cumul -= dx ;
  y += 1 ; }
  allume_pixel(x,y) ; } 
  }
*/

/*
  void ligne(int xi,int yi,int xf,int yf) {
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = abs(dx) ;
  dy = abs(dy) ;
  allume_pixel(x,y) ;
  if ( dx > dy ) {
  cumul = dx / 2 ;
  for ( i = 1 ; i <= dx ; i++ ) {
  x += xinc ;
  cumul += dy ;
  if ( cumul >= dx ) {
  cumul -= dx ;
  y += yinc ; }
  allume_pixel(x,y) ; } }
  else {
  cumul = dy / 2 ;
  for ( i = 1 ; i <= dy ; i++ ) {
  y += yinc ;
  cumul += dx ;
  if ( cumul >= dy ) {
  cumul -= dy ;
  x += xinc ; }
  allume_pixel(x,y) ; } }
  }
*/