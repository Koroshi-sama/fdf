/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:32:04 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/22 02:18:07 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	connection_y(t_fdf fd)
{
	float	xinc;
	float	yinc;
	float	step;

	if (fd.map[fd.x][fd.y].color == 0)
		fd.map[fd.x][fd.y].color = 0xFFFFFF;
	fd.y1 = fd.y1 - (fd.z * 2);
	fd.y2 = fd.y2 - (fd.zz * 2);
	if ((fd.x2 - fd.x1) > (fd.y2 - fd.y1))
		step = (fd.x2 - fd.x1) + abs(fd.zz);
	else
		step = (fd.y2 - fd.y1) + abs(fd.zz);
	fd.x1 = fd.x1 - (fd.z * 2);
	fd.x2 = fd.x2 - (fd.zz * 2);
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

void	one_line_y(t_fdf fd)
{
	int	i;

	i = 1;
	fd.x2 = fd.x1 + fd.pixels;
	fd.y2 = fd.y1;
	fd.y = 0;
	while (i++ < fd.count_y)
	{
		fd.z = fd.map[fd.x][fd.y].atitude;
		fd.zz = fd.map[fd.x][fd.y + 1].atitude;
		connection_y(fd);
		fd.x1 += fd.pixels;
		fd.x2 += fd.pixels;
		fd.y++;
	}
}

void	multi_lines_y(t_fdf fd)
{
	fd.x = 0;
	while (fd.x < fd.count_x)
	{
		one_line_y(fd);
		fd.y1 += fd.pixels;
		fd.x++;
	}
}
