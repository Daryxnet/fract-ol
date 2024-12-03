/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:47:58 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/02 14:48:04 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(void)
{
    printf("Usage:\n");
    printf("./fractol mandelbrot\n");
    printf("./fractol julia <Re> <Im>\n");
    printf("./fractol burning_ship\n");
}

int parse_arguments(int argc, char **argv)
{
    if (argc < 2)
    {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "mandelbrot") == 0)
        return 0;
    else if (strcmp(argv[1], "julia") == 0)
    {
        if (argc != 4)
        {
            print_usage();
            return 1;
        }
        return 0;
    }
    else if (strcmp(argv[1], "burning_ship") == 0)
        return 0;
    else
    {
        print_usage();
        return 1;
    }
}

