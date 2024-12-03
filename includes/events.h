/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:20:53 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/03 22:22:04 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractal.h"

int	on_destroy_event(t_engine *engine);
int	on_mouse_hook_event(int key, int x, int y, t_engine *engine);
int	on_key_hook_event(int key, t_engine *engine);
int	on_mousemove_event(int x, int y, t_engine *engine);

#endif
