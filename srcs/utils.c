/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:27:27 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/19 12:54:59 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}

void	ft_strlower(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void	print(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}

void	show_help(void)
{
	print("\n", 1);
	print(" Usage: ./fractol [mandelbrot / julia / burning_ship\n", 1);
	print("                 tricorn / mandelbox / celtic_mandelbar]\n", 1);
	print(" 	   Press L to Block Julia\n", 1);
	print("\n", 1);
	exit(EXIT_SUCCESS);
}
