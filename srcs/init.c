# include "../includes/fractol.h"

void  init_fractol(t_data *fractol)
{
  fractol->x = 0;
  fractol->y = 0;
  fractol->color = 0xFFFFFF;
  fractol->zoom = 300;
  fractol->x_offset = -1.21;
  fractol->y_offset = -1.21;
  fractol->iterations = 42;
}

void  init_mlx(t_data *fractol)
{
  fractol->mlx = mlx_init();
  fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "fract-ol");
  fractol->image = mlx_new_window(fractol->mlx, SIZE, SIZE);
  fractol->addr = mlx_get_data_addr(fractol->image, &fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
}
