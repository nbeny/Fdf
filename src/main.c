#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	(void)ac;
	(void)av;
	x = 200;
	y = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	mlx_loop(mlx);
	return (0);
}
