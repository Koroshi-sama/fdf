/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:31:59 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/22 03:52:28 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	connection_x(t_fdf fd)
{
	float	xinc;
	float	yinc;
	float	step;

	if (fd.map[fd.x][fd.y].color == 0)
		fd.map[fd.x][fd.y].color = 0xFFFFFF;
	fd.x1 = fd.x1 - (fd.s * 2);
	fd.x2 = fd.x2 - (fd.ss * 2);
	if ((fd.x2 - fd.x1) > (fd.y2 - fd.y1))
		step = (fd.x2 - fd.x1) + abs(fd.ss);
	else
		step = (fd.y2 - fd.y1) + abs (fd.ss);
	fd.y1 = fd.y1 - (fd.s * 2);
	fd.y2 = fd.y2 - (fd.ss * 2);
	xinc = (fd.x2 - fd.x1) / step;
	yinc = (fd.y2 - fd.y1) / step;
	while (step--)
	{
		fd.iso_x = (fd.x1 - fd.y1) + fd.hold;
		fd.iso_y = ((fd.x1 + fd.y1) / 2);
		pixel_put(&fd, fd.iso_x, fd.iso_y, fd.map[fd.x][fd.y].color);
		fd.x1 += xinc;
		fd.y1 += yinc;
	}
}

void	one_line_x(t_fdf fd)
{
	int	i;

	i = 1;
	fd.x2 = fd.x1;
	fd.y2 = fd.y1 + fd.pixels;
	fd.x = 0;
	while (i++ < fd.count_x)
	{
		fd.s = fd.map[fd.x][fd.y].atitude;
		fd.ss = fd.map[fd.x + 1][fd.y].atitude;
		connection_x(fd);
		fd.y1 += fd.pixels;
		fd.y2 += fd.pixels;
		fd.x++;
	}
}

void	multi_lines_x(t_fdf fd)
{
	fd.y = 0;
	while (fd.y < fd.count_y)
	{
		one_line_x(fd);
		fd.x1 += fd.pixels;
		fd.y++;
	}
}
