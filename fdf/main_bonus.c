/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:45:27 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 01:14:30 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	map_parsing(t_fdf *fd)
{
	fd->count_x = count_x(fd);
	fd->count_y = count_y(fd->fdf_map->content);
	fd->pixels = pixels(*fd);
	fd->map = (t_fdf **)malloc(sizeof(t_fdf *) * fd->count_x);
	if (!fd->map)
		exit(0);
	fd->x = 0;
	while (fd->fdf_map)
	{
		map_array(fd->fdf_map->content, *fd);
		free(fd->fdf_map);
		free(fd->fdf_map->content);
		fd->fdf_map = fd->fdf_map->next;
		fd->x++;
	}
	fd->x1 = 200;
	fd->y1 = 200;
}

void	map_array(char *line, t_fdf fd)
{
	char	**li;

	li = ft_split(line, ' ', fd);
	fd.map[fd.x] = (t_fdf *)malloc(sizeof(t_fdf) * fd.count_y + 1);
	fd.y = 0;
	while (li[fd.y])
	{
		if (li[fd.y][0] == '\n')
			break ;
		fd.map[fd.x][fd.y].atitude = ft_atoi(li[fd.y], &fd);
		fd.map[fd.x][fd.y].color = fd.hex;
		free(li[fd.y]);
		fd.y++;
	}
	if (fd.y != fd.count_y)
	{
		write(1, "Invalid size of map !\n", 22);
		exit(0);
	}
	free(li[fd.y]);
	free(li);
}

void	fdf_first(t_fdf *fd)
{
	int	x;

	x = (((fd->count_x + fd->count_y) / 1.1) * fd->pixels) + 300;
	if (((fd->count_y - fd->count_x) > 7) || ((fd->count_x - fd->count_y) > 7))
		fd->hold = x / 2.6;
	else
		fd->hold = x / 2;
	fd->mlx_w = mlx_new_window(fd->mlx, x, x, "FDF");
	mlx_key_hook(fd->mlx_w, key_hook, &fd);
	mlx_hook(fd->mlx_w, 17, 0, exit_if_close, NULL);
	fd->img = mlx_new_image(fd->mlx, x, x);
	fd->addr = mlx_get_data_addr(fd->img, &fd->bits_per_pixel, &fd->line_length,
			&fd->endian);
	multi_lines_x(*fd);
	multi_lines_y(*fd);
	
	mlx_put_image_to_window(fd->mlx, fd->mlx_w, fd->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		write(1, "Error : more or less paramters than it should!\n", 47);
		return (0);
	}
	check_fdf(argv[1]);
	fdf.av = argv[1];
	fdf.mlx = mlx_init();
	map_parsing(&fdf);
	fdf_first(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
