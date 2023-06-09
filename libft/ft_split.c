/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:34:04 by leeyang           #+#    #+#             */
/*   Updated: 2023/04/04 16:14:12 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_str(char const *s, char const c)
{
	size_t	i;
	size_t	strcount;

	i = 0;
	strcount = 0;
	if (s[0] != '\0' && s[0] != c)
		strcount++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			strcount++;
		i++;
	}
	return (strcount);
}

static size_t	count_char(char const *s, char const c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	*newstr(char const *s, char c)
{
	size_t	i;
	size_t	charcount;
	char	*str;

	i = 0;
	charcount = count_char(s, c);
	str = (char *)malloc(sizeof(char) * (charcount + 1));
	if (str == NULL)
		return (NULL);
	while (i < charcount)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	p;
	size_t	strcount;
	char	**ar;

	i = 0;
	p = 0;
	if (s == NULL)
		return (NULL);
	strcount = count_str(s, c);
	ar = (char **)malloc(sizeof(char *) * (strcount + 1));
	if (ar == NULL)
		return (NULL);
	while (i < strcount)
	{
		while (s[p] != '\0' && s[p] == c)
			p++;
		ar[i] = newstr(s + p, c);
		while (s[p] != '\0' && s[p] != c)
			p++;
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
