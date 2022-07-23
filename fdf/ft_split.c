/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:49:14 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 01:13:24 by aerrazik         ###   ########.fr       */
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
	int		i;
	int		j;
	int		b;
	int		v;

	if(!s)
		return(0);
	spl = (char **)malloc(sizeof(char *) * (fd.count_y + 1));
	if (!spl)
		return (NULL);
	i = -1;
	j = 0;
	b = -1;
	v = ft_strlenn(s);
	while (++i <= v)
	{
		if (s[i] != c && s[i] && b == -1)
			b = i;
		if ((s[i] == c || s[i] == '\0') && b >= 0)
		{
			spl[j++] = sp(s, i, b);
			b = -1;
		}
	}
	spl[j] = 0;
	return (spl);
}
