/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:00:24 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 05:00:15 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_fdf *fd)
{
	fd = 0;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	count_y(char *str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (str[0] == ' ')
		i++;
	while (str[i])
	{
		if ((str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			&& str[i - 1] == ' ')
			j++;
		i++;
	}
	return (j);
}

int	count_x(t_fdf *fd)
{
	char	*line;
	int		f_d;
	int		i;
	t_fdf	*crea_node;

	i = 0;
	f_d = open(fd->av, O_RDONLY);
	if (f_d < 0)
	{
		write(1, "File don't exist!\n", 18);
		exit(0);
	}
	line = get_next_line(f_d);
	fd->fdf_map = NULL;
	while (line)
	{
		i++;
		crea_node = ft_lstnew(line);
		ft_lstadd_back(&fd->fdf_map, crea_node);
		line = get_next_line(f_d);
	}
	return (i);
}

int	pixels(t_fdf fd)
{
	int	pic;

	if (fd.count_x > fd.count_y)
		pic = fd.count_x;
	else
		pic = fd.count_y;
	if (pic <= 15)
		return (25);
	else if (pic <= 25)
		return (23);
	else if (pic <= 40)
		return (20);
	else if (pic <= 60)
		return (15);
	else if (pic <= 100)
		return (10);
	else if (pic > 200)
		return (2);
	return (6);
}
