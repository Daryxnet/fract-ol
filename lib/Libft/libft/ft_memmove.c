/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:18:26 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/11 16:07:51 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*de;
	unsigned char	*sr;

	de = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (de >= sr)
	{
		while (n--)
			de[n] = sr[n];
	}
	else
		ft_memcpy(de, sr, n);
	return (dest);
}
