# include "../includes/fractol.h"


void  handle_zoom(t_data *fractol, int x, int y, int zoom)
{
  double  level;

  level = 1.42;
  if (zoom == 1)
  {
    fractol->x_offset = (x / fractol->zoom + fractol->x_offset) - (x / (fractol->zoom * level));
    fractol->y_offset = (y / fractol->zoom + fractol->y_offset) - (y / (fractol->zoom * level));
    fractol->zoom *= level;
  }
  else if (zoom == -1)
  {
    fractol->x_offset = (x / fractol->zoom + fractol->x_offset) - (x / (fractol->zoom / level));
    fractol->y_offset = (y / fractol->zoom + fractol->y_offset) - (y / (fractol->zoom / level));
    fractol->zoom /= level;
  }
  else
    return ;
}

void  random_julia(double *c_r, double *c_i)
{
  *c_r = generate_constant();
  *c_i = generate_constant();
}

int handole_key(int code, t_data *fractol)
{
  if (code == ESC)
    exit(1);
  else if (code == UP)
    fractol->y_offset -= 42 / fractol->zoom;
  else if (code == DOWN)
    fractol->y_offset += 42 / fractol->zoom;
  else if (code == RIGHT)
    fractol->x_offset += 42 / fractol->zoom;
  else if (code == LEFT)
    fractol->x_offset -= 42 / fractol->zoom;
  else if (code == R)
    init_fractol(fractol);
  else if (code == C)
    fractol->color += (255 * 255 * 255) / 100;
  else if (code == J)
    random_julia(&fractol->c_r, &fractol->c_i);
  else if (code == P || code == M)
    change_iterations(fractol, code);
  draw_fractol(fractol, fractol->name);
  return (0);
}

int handle_mouse(int code, int x, int y, t_data *fractol)
{
  if (code == SCROLL_UP)
    handle_zoom(fractol, x, y, 1);
  else if (code == SCROLL_DOWN)
    handle_zoom(fractol, x, y, -1);
  return (0);
}
