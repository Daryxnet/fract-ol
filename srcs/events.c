/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:09:20 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/04 19:28:38 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>
#include "events.h"
#include "render.h"
#include "make_engine.h"

int	on_destroy_event(void *param)
{
	t_engine *engine = (t_engine *)param;

	mlx_destroy_image(engine->mlx, engine->image.img_ptr);
	mlx_destroy_window(engine->mlx, engine->window);
	mlx_terminate(engine->mlx);
	exit(EXIT_SUCCESS);
}

int	on_mouse_hook_event(int button, int x, int y, void *param)
{
	t_engine *engine = (t_engine *)param;
	t_fractal *fr = &engine->fractal;

	if (button == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		if (fr->iterations < MAX_ITERATIONS)
			++fr->iterations;
	}
	else if (button == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		if (fr->iterations > MIN_ITERATIONS)
			--fr->iterations;
	}
	draw_fractal(engine);
	return (0);
}

int	on_key_hook_event(int key, void *param)
{
	t_engine *engine = (t_engine *)param;

	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		change_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_UP)
		change_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FIVE)
		change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.is_julia_lock ^= 1;
	else if (key == KEY_ZERO)
		reset_engine(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(engine);
	draw_fractal(engine);
	return (0);
}

int	on_mousemove_event(int x, int y, void *param)
{
	t_engine *engine = (t_engine *)param;

	if (!(engine->fractal.type == JULIA) || engine->fractal.is_julia_lock)
		return (0);
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	draw_fractal(engine);
	return (0);
}
