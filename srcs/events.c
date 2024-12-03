/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:09:20 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/03 14:40:10 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

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

