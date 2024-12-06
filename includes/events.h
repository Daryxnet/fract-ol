/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:20:53 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/04 19:30:43 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractal.h"

int	on_destroy_event(void *param);
int	on_mouse_hook_event(int button, int x, int y, void *param);
int	on_key_hook_event(int key, void *param);
int	on_mousemove_event(int x, int y, void *param);

#endif
