# include "../includes/fractol.h"

void  calculate_mandelbrot(t_data *fractol)
{
  int i;
  double  tmp;

  fractol->name = "mandelbrot";
  i = 0;
  fractol->r = 0.0;
  fractol->i = 0.0;
  fractol->c_r = (fractol->x / fractol->zoom) + fractol->x_offset;
  fractol->c_i = (fractol->y / fractol->zoom) + fractol->y_offset;
  while (++i < fractol->iterations)
  {
    tmp = fractol->r * fractol->r - fractol->i * fractol->i + fractol->c_r; // real part
    fractol->i = 2. * fractol->r * fractol->i + fractol->c_i;
    fractol->r = tmp;
    if (fractol->r * fractol->r + fractol->i * fractol->i >= 2)
      break;
  }
  if (i == fractol->iterations)
    put_color_to_pixel(fractol, fractol->r, fractol->i, 0x000000);
  else
    put_color_to_pixel(fractol, fractol->r, fractol->i, (fractol->color * i));
}
