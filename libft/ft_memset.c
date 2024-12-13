/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:59:09 by dagarmil          #+#    #+#             */
/*   Updated: 2024/12/13 17:59:14 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*mem;
	unsigned char	ch;
	size_t			i;

	i = 0;
	mem = (char *)b;
	ch = (unsigned char)c;
	while (i < len)
	{
		mem[i] = ch;
		++i;
	}
	return (b);
}
