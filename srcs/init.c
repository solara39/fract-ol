/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:18 by skondo            #+#    #+#             */
/*   Updated: 2024/05/04 16:12:24 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

void  init_fractol(t_data *fractol)
{
  fractol->x = 0;
  fractol->y = 0;
  fractol->color = 0xFCBE11;
  fractol->zoom = 300;
  fractol->x_offset = -1.21;
  fractol->y_offset = -1.21;
  fractol->iterations = 42;
}

void  init_mlx(t_data *fractol)
{
  fractol->mlx = mlx_init();
  fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "fract-ol");
  fractol->image = mlx_new_image(fractol->mlx, SIZE, SIZE);
  fractol->addr = mlx_get_data_addr(fractol->image, &fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
}
