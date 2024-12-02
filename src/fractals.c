/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:46:45 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/02 15:18:07 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

#define MAX_ITER 100

uint32_t get_color(int iterations)
{
    if (iterations == MAX_ITER)
        return 0x000000FF; // Negro (dentro del conjunto)
    return 0xFFFFFF00 | (iterations * 10); // Gradiente de color
}

void draw_mandelbrot(mlx_image_t *image)
{
    double min_re = -2.0;
    double max_re = 1.0;
    double min_im = -1.5;
    double max_im = min_im + (max_re - min_re) * HEIGHT / WIDTH;

    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            double c_re = min_re + x * (max_re - min_re) / (WIDTH - 1);
            double c_im = max_im - y * (max_im - min_im) / (HEIGHT - 1);
            double z_re = c_re, z_im = c_im;

            int iter;
            for (iter = 0; iter < MAX_ITER; ++iter)
            {
                double z_re2 = z_re * z_re;
                double z_im2 = z_im * z_im;
                if (z_re2 + z_im2 > 4.0)
                    break;

                double temp = z_re2 - z_im2 + c_re;
                z_im = 2.0 * z_re * z_im + c_im;
                z_re = temp;
            }
            mlx_put_pixel(image, x, y, get_color(iter));
        }
    }
}

void draw_julia(mlx_image_t *image, double c_re, double c_im)
{
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            double z_re = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
            double z_im = (y - HEIGHT / 2) / (0.5 * HEIGHT);

            int iter;
            for (iter = 0; iter < MAX_ITER; ++iter)
            {
                double z_re2 = z_re * z_re;
                double z_im2 = z_im * z_im;
                if (z_re2 + z_im2 > 4.0)
                    break;

                double temp = z_re2 - z_im2 + c_re;
                z_im = 2.0 * z_re * z_im + c_im;
                z_re = temp;
            }
            mlx_put_pixel(image, x, y, get_color(iter));
        }
    }
}
/*
void draw_burning_ship(mlx_image_t *image)
{
    // Implementación similar a Mandelbrot, pero usando la fórmula Burning Ship
}
*/
