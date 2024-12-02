/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:00:55 by dagarmil          #+#    #+#             */
/*   Updated: 2024/06/28 13:25:09 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*nstr;
	size_t	i;

	if (!s)
		return (NULL);
	nstr = (char *)malloc(sizeof(s) * (ft_strlen(s) + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
