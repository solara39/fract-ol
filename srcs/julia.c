/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:33:17 by skondo            #+#    #+#             */
/*   Updated: 2024/05/04 16:21:16 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

void  calculate_julia(t_data  *fractol)
{
  int i;
  double  tmp;

  i = 0;
  fractol->name = "julia";
  fractol->r = fractol->x / fractol->zoom + fractol->x_offset;
  fractol->i = fractol->y / fractol->zoom + fractol->y_offset;
  while (++i < fractol->iterations)
  {
    tmp = fractol->r;
    fractol->r = fractol->r * fractol->r - fractol->i * fractol->i + fractol->c_r;
    fractol->i = 2 * fractol->i * tmp + fractol->c_i;
    if (fractol->r * fractol->r + fractol->i * fractol->i >= __DBL_MAX__)
      break;
  }
  if (i == fractol->iterations)
    put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
  else
    put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i % 255)));
}
