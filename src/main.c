/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:30 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/02 19:03:29 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

int main(int argc, char **argv)
{
    if (parse_arguments(argc, argv))
        return EXIT_FAILURE;

    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
    if (!mlx)
        return EXIT_FAILURE;

    mlx_image_t *image = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!image)
    {
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "mandelbrot") == 0)
        draw_mandelbrot(image);
    else if (strcmp(argv[1], "julia") == 0)
        draw_julia(image, atof(argv[2]), atof(argv[3]));  // Re, Im de Julia
    /*else if (strcmp(argv[1], "burning_ship") == 0)
        draw_burning_ship(image);
*/
    if (mlx_image_to_window(mlx, image, 0, 0) < 0)
    {
        mlx_delete_image(mlx, image);
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    init_hooks(mlx, image);
    mlx_loop(mlx);
    mlx_delete_image(mlx, image);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}

