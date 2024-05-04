/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:31:37 by skondo            #+#    #+#             */
/*   Updated: 2024/05/04 16:32:17 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

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
    if (fractol->r * fractol->r + fractol->i * fractol->i >= __DBL_MAX__)
      break;
  }
  if (i == fractol->iterations)
    put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
  else
    put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * i));
}
