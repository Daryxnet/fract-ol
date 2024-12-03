/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:30 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/03 22:26:11 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_engine	engine;
	/*
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
    if (!mlx)
        return (1);

    mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!image)
    {
        mlx_terminate(mlx);
        return (1);
    }

	t_fractal	fract;
	fract.iterations = MAX_ITER;
	fract.min_re = -2.0;
	fract.max_re = 1.0;
	fract.min_im = -1.5;
	fract.max_im = fract.min_im + (fract.max_re - fract.min_re) * HEGHT / WIDTH;

    draw_mandelbrot(image); // Dibujar el fractal de Mandelbrot

    mlx_image_to_window(mlx, image, 0, 0);

    mlx_loop(mlx);
    mlx_terminate(mlx);*/
    return (0);
}

