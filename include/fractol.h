/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:49:04 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/02 19:07:33 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "MLX42.h"
#include <string.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_zoom
{
    double zoom_level;
    double offset_x;
    double offset_y;
    mlx_image_t *image;
} t_zoom;

void draw_mandelbrot(mlx_image_t *image);
void draw_julia(mlx_image_t *image, double c_re, double c_im);
void draw_burning_ship(mlx_image_t *image);
void init_hooks(mlx_t *mlx, mlx_image_t *image);

uint32_t get_color(int iterations);

int parse_arguments(int argc, char **argv);
void print_usage(void);

#endif

