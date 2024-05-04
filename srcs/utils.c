/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:48:34 by skondo            #+#    #+#             */
/*   Updated: 2024/04/29 18:11:58 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

void  put_color_to_pixel(t_data *fractol, int x, int y, int color)
{
  int *buf;

  buf = fractol->addr;
  buf[(y * fractol->size_line / 4) + x] = color;
}

int exit_fractol(t_data *fractol)
{
  mlx_destroy_image(fractol->mlx, fractol->image);
  mlx_destroy_window(fractol->mlx, fractol->window);
  free(fractol->mlx);
  free(fractol);
  exit(1);
  return (0);
}

double  generate_constant()
{
  return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

void  change_iteration(t_data *fractol, int code)
{
  if (code == M)
  {
    if (fractol->iterations > 42)
      fractol->iterations -= 42;
  }
  else if (code == P)
  {
    if (fractol->iterations < 4200)
      fractol->iterations += 42;
  }
}
