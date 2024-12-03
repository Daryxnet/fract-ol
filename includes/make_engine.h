/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:28:39 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/03 22:29:17 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_ENGINE_H
# define MAKE_ENGINE_H

# include "fractal.h"

void	change_fractal(int key, t_engine *engine);
void	set_fractal_type(t_engine *engine, char *str);
void	reset_engine(t_engine *engine, int fractal_type);
void	init_engine(t_engine *engine, char *arg);

#endif 
