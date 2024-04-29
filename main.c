/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:56:46 by skondo            #+#    #+#             */
/*   Updated: 2024/04/29 19:29:57 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
# include "include/fractol.h"

int draw_fractol(t_data *fractol, char *argv)
{
  if (ft_strncmp(argv, "mandelbrot", 10) == 0) // made
    draw_mandelbrot(fractol);
  else if (ft_strncmp(argv, "julia", 5) == 0)
  {
    init_fractol(fractol);
    draw_julia(fractol);
  }
  else
  {
    //ft_putendl_fd("not appropriate argument", 1);
    exit_fractol(fractol);
  }
  mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0, 0);
  return (0);
}

int	main(int argc, char **argv)
{
	t_data	*fractol;

	if (argc != 2)
	{
		//ft_putendl_fd("inappropriate arguments", 1);
		return (0);
	}
	fractol = malloc(sizeof(t_data));
	if (fractol == NULL)
		return (0);
	init_fractol(fractol);
	init_mlx(fractol);
	//mlx_key_hook(fractol->window, handle_key, fractol);
	mlx_mouse_hook(fractol->window, handle_mouse, fractol);
	mlx_hook(fractol->window, 17, 0L, exit_fractol, fractol);
	draw_fractol(fractol, argv[1]);
	mlx_loop(fractol->mlx);
	return (0);
}


