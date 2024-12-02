/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:09:20 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/02 19:02:54 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

double zoom_level = 1.0;
mlx_image_t	*image;

// Función para manejar el evento de la tecla
void key_hook(mlx_key_data_t keydata, void *param)
{
    mlx_t *mlx = (mlx_t *)param;

    // Verificamos si la tecla presionada es ESC (para cerrar la ventana)
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_close_window(mlx);  // Cierra la ventana
    }
}

// Función para manejar el evento del ratón
void scroll_hook(double xdelta, double ydelta, void *param)
{
	 t_zoom *zoom = (t_zoom *)param;  // Casteo a la estructura t_zoom

    if (ydelta > 0)
    {
        zoom->zoom_level *= 1.1;  // Aumenta el zoom
    }
    else if (ydelta < 0)
    {
        zoom->zoom_level /= 1.1;  // Disminuye el zoom
    }

    printf("Zoom level: %f\n", zoom->zoom_level);

    // Redibujar la imagen con el nuevo zoom
    mlx_clear_window(zoom->image->mlx, zoom->image->mlx_window);
    draw_image(zoom->image, zoom->zoom_level, zoom->offset_x, zoom->offset_y);  // Función para dibujar con zoom
}
// Esta función dibuja la imagen en función del nivel de zoom y el desplazamiento
void draw_image(mlx_image_t *image, double zoom_level, double offset_x, double offset_y)
{
    int width = image->width;
    int height = image->height;
    int max_iter = 1000;  // Número máximo de iteraciones para el fractal
    double zx, zy, cx, cy, tmp;
    int iter;
    int color;

    // Recorre cada píxel de la ventana
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Escala las coordenadas según el nivel de zoom y el desplazamiento
            zx = (x - width / 2) / zoom_level + offset_x;
            zy = (y - height / 2) / zoom_level + offset_y;
            cx = zx;
            cy = zy;
            iter = 0;

            // Calcula el valor del fractal (ejemplo con Mandelbrot)
            while (zx * zx + zy * zy < 4 && iter < max_iter)
            {
                tmp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmp;
                iter++;
            }

            // Calcula el color basado en el número de iteraciones
            if (iter == max_iter)
                color = 0x000000;  // Negro, punto dentro del conjunto
            else
                color = iter * 255 / max_iter;  // Colores más brillantes para puntos fuera del conjunto

            // Coloca el color del píxel en la imagen
            mlx_put_pixel(image, x, y, color);
        }
    }
}
// Función para inicializar y ejecutar los eventos
void init_hooks(mlx_t *mlx, mlx_image_t *image)
{
	 t_zoom *zoom = malloc(sizeof(t_zoom));
    if (!zoom)
    {
        printf("Error al asignar memoria para el zoom\n");
        return;
    }

    zoom->zoom_level = 1.0;
    zoom->offset_x = 0;
    zoom->offset_y = 0;
    zoom->image = image;

    mlx_key_hook(mlx, key_hook, zoom);
    mlx_scroll_hook(mlx, scroll_hook, zoom);  // Pasamos la estructura zoom
}

