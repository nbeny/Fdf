#include "fdf.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	mlx_pixel_put(mlx, win, 200, 200, 0xFFFFFF);
	mlx_loop(mlx);
	return (0);
}
