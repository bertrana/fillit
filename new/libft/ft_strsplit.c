/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:35:14 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/05 17:42:33 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_l(char *str, int i, char c)
{
	int			len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len + 1);
}

static int		ft_c(char *str, char c)
{
	int			count;
	int			s;
	int			i;

	i = 0;
	s = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			s = 1;
		}
		if (str[i] == c || !str[i])
		{
			if (s == 1)
				count++;
			s = 0;
			i++;
		}
	}
	return (count);
}

static char		**ft_free(int j, char **m)
{
	while (j >= 0)
		free(m[j--]);
	free(m);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**m;
	int			i;
	int			j;
	int			k;

	j = 0;
	i = 0;
	if (!s || !(m = (char **)malloc(sizeof(char*) * (ft_c((char *)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(m[j] = (char *)malloc(sizeof(char) * ft_l((char *)s, i, c))))
				return (ft_free(j, m));
			while (s[i] != c && s[i])
				m[j][k++] = s[i++];
			m[j++][k] = '\0';
		}
	}
	m[j] = NULL;
	return (m);
}
