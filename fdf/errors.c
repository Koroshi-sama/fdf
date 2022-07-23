/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:54:17 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 04:24:15 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	check_fdf(char *str)
{
	int		i;
	char	*fdf;
	int		j;

	i = ft_strlen(str) - 1;
	fdf = "fdf.";
	j = 0;
	while (fdf[j])
	{
		if (fdf[j] != str[i])
		{
			write(1, "Error : file not compatible\n", 28);
			exit(0);
		}
		else
		{
			i--;
			j++;
		}
	}
}

int	exit_if_close(void)
{
	exit(0);
	return (0);
}
