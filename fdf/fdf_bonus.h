/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:28:34 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 00:48:49 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include"mlx.h"
# include"get_next_line.h"
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<math.h>

typedef struct s_fdf
{
	void			*mlx;
	void			*mlx_w;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	char			*av;
	int				count_x;
	int				count_y;
	struct s_fdf	**map;
	int				x;
	int				y;
	float			x1;
	float			y1;
	int				j;
	int				i;
	int				zoom;
	int				atitude;
	int				color;
	float			x2;
	float			y2;
	int				s;
	int				ss;
	int				z;
	int				zz;
	float			hold;
	float			iso_x;
	float			iso_y;
	int				pixels;
	char			*content;
	struct s_fdf	*next;
	struct s_fdf	*fdf_map;
	int				hex;
}	t_fdf;

void	check_fdf(char *str);
void	pixel_put(t_fdf *data, int x, int y, int color);
int		key_hook(int keycode, t_fdf *fd);
char	*sp(const char *s, int e, int b);
char	**ft_split(char const *s, char c, t_fdf fd);
int		ft_atoi(char *str, t_fdf *fd);
int		count_y(char *str);
int		count_x(t_fdf *fd);
int		exit_if_close(void);
void	map_array(char *line, t_fdf fd);
int		pixels(t_fdf fd);
void	connection_x(t_fdf fd);
void	one_line_x(t_fdf fd);
void	multi_lines_x(t_fdf fd);
void	multi_lines_y(t_fdf fd);
void	connection_y(t_fdf fd);
void	one_line_y(t_fdf fd);
t_fdf	*ft_lstnew(char *content);
t_fdf	*ft_lstlast(t_fdf *lst);
void	ft_lstadd_back(t_fdf **alst, t_fdf *nw);
void	hex_color(char *str, int i, t_fdf *fd);
void	ft_lstclear(t_fdf **lst);

#endif
