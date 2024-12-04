/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:45:30 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/04 15:47:43 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		show_help();

	// Inicializa el motor de fractales
	init_engine(&engine, argv[1]);

	// Dibuja el fractal en la ventana
	draw_fractal(&engine);

	// Registra los eventos de teclado
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine.window, on_mouse_hook_event, &engine);
	mlx_hook(engine.window, MLX42_MOUSE_MOVE, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine.window, MLX42_EVENT_DESTROY, 0, on_destroy_event, &engine);

	// Entra en el loop de la librería
	mlx_loop(engine.mlx);

	return (0);
}
/*int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		show_help();
	init_engine(&engine, argv[1]);
	draw_fractal(&engine);
	
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
    mlx_terminate(mlx);
    return (0);
}*/

