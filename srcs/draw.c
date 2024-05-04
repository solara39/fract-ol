/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:44 by skondo            #+#    #+#             */
/*   Updated: 2024/05/04 16:33:28 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

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

void  draw_julia(t_data *fractol)
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
