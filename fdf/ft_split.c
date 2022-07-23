/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:49:14 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 04:26:36 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_strlenn(const char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

char	*sp(const char *s, int e, int b)
{
	int		i;
	char	*sp;

	sp = (char *)malloc(sizeof(char) * (e - b + 1));
	if (!sp)
		return (0);
	i = 0;
	while (b < e)
	{
		sp[i] = s[b];
		i++;
		b++;
	}
	sp[i] = '\0';
	return (sp);
}

char	**ft_split(char const *s, char c, t_fdf fd)
{
	char	**spl;
	int		j;
	int		v;

	if (!s)
		return (0);
	spl = (char **)malloc(sizeof(char *) * (fd.count_y + 1));
	if (!spl)
		return (NULL);
	fd.i = -1;
	j = 0;
	fd.b = -1;
	v = ft_strlenn(s);
	while (++fd.i <= v)
	{
		if (s[fd.i] != c && s[fd.i] && fd.b == -1)
			fd.b = fd.i;
		if ((s[fd.i] == c || s[fd.i] == '\0') && fd.b >= 0)
		{
			spl[j++] = sp(s, fd.i, fd.b);
			fd.b = -1;
		}
	}
	spl[j] = 0;
	return (spl);
}
