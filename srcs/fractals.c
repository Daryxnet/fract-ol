/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:46:45 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/04 19:15:42 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "math.h"

// Calcula Mandelbrot
int calc_mandelbrot(t_fractal *fract, t_complex *c)
{
    double		re_temp;
    t_complex	z;
    int			i;
   
	i = -1;
    z.re = 0;
    z.im = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = 2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}

// Calcula Julia
int calc_julia(t_fractal *fract, t_complex *c, int x, int y)
{
    double		re_temp;
    t_complex	z;
    int			i;
		
	i = -1;
    z.re = (x / fract->zoom) + fract->offset_x;
    z.im = (y / fract->zoom) + fract->offset_y;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = 2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}

// Calcula Burning Ship
int calc_burning_ship(t_fractal *fract, t_complex *c)
{
    double		re_temp;
    t_complex	z;
    int			i;
   
	i = -1;
    z.re = 0;
    z.im = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = fabs(2 * z.re * z.im) + c->im;
        z.re = fabs(re_temp);
    }
    return (i);
}

// Calcula Tricorn
int calc_tricorn(t_fractal *fract, t_complex *c)
{
    double		re_temp;
    t_complex	z;
    int			i;
   
	i = -1;
    z.re = 0;
    z.im = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im + c->re;
        z.im = -2 * z.re * z.im + c->im;
        z.re = re_temp;
    }
    return (i);
}

// Calcula Celtic Mandelbar
int calc_celtic_mandelbar(t_fractal *fract, t_complex *c)
{
    double		re_temp;
    t_complex	z;
    int			i;
   
	i = -1;
    z.re = 0;
    z.im = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && ++i < fract->iterations)
    {
        re_temp = z.re * z.re - z.im * z.im;
        z.im = -2 * z.re * z.im + c->im;
        if (re_temp < 0)
            re_temp *= -1;
        z.re = re_temp + c->re;
    }
    return (i);
}
