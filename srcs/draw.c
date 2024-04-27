# include "../includes/fractol.h"

void  draw_mandelbrot(t_data *fractol)
{
  fractol->x = 0;
  fractol->y = 0;
  while (fractol->x < SIZE)
  {
    while (fractol->y < SIZE)
    {
      calculate_mandelbrot(fractol);
      fractol->y++;
    }
    fractol->x++;
    fractol->y = 0;
  }
}

void  *draw_julia(t_data *fractol)
{
  fractol->x = 0;
  fractol->y = 0;
  while (fractol->x < SIZE)
  {
    while (fractol->y < SIZE)
    {
      calculate_julia(fractol);
      fractol->y++;
    }
    fractol->x++;
    fractol->y = 0;
  }
}
