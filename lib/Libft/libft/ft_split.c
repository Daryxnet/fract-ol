/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:10:35 by dagarmil          #+#    #+#             */
/*   Updated: 2024/07/10 18:01:50 by dagarmil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cw;

	cw = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			cw++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	cw++;
	return (cw);
}

static void	*ft_free(char **memo, size_t buff)
{
	size_t	i;

	i = 0;
	while (i < buff)
	{
		free(memo[i]);
		i++;
	}
	free(memo);
	return (NULL);
}

static void	ft_armk(char **array, char *nstr, char c, int cws)
{
	int		i;
	char	*strchr;

	i = 0;
	if ((cws > 0) && *nstr)
	{
		while (i < (cws - 1))
		{
			strchr = ft_strchr(nstr, c);
			array[i++] = ft_substr(nstr, 0, strchr - nstr);
			if (array == 0)
			{
				ft_free(array, i);
				return ;
			}
			while (*strchr == c)
				strchr++;
			nstr = strchr;
		}
		array[i++] = ft_strdup(nstr);
		array[i] = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	int		cws;
	char	**array;
	char	*nstr;
	char	corn[2];

	corn[0] = c;
	corn[1] = '\0';
	if (s)
	{
		nstr = ft_strtrim(s, corn);
		if (nstr)
		{
			cws = count_words(nstr, c);
			array = ft_calloc((cws + 1), sizeof(char *));
			if (array)
				ft_armk(array, nstr, c, cws);
			free(nstr);
			return (array);
		}
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	char	*str;
	char	**narray;
	char	x;
	int		i;

	x = ' ';
	i = 0;
	str = "      Ho la Co mo Es tas   ";
	narray = ft_split(str, x);
	while (narray[i])
	{
		printf("strings resultantes: %s\n", narray[i]);
		i++;
	}
	free(narray);
	return (0);
}*/
