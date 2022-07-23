/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:49:34 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 04:27:24 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	hex_color(char *str, int i, t_fdf *fd)
{
	int	hex;

	hex = 0;
	i = i + 3;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			hex = hex * 16 + (str[i++] - 55);
		else if (str[i] >= 'a' && str[i] <= 'f')
			hex = hex * 16 + (str[i++] - 87);
		else if (str[i] >= '0' && str[i] <= '9')
			hex = hex * 16 + (str[i++] - 48);
		else
			break ;
	}
	fd->hex = hex;
}

int	ft_atoi(char *str, t_fdf *fd)
{
	int	r;
	int	s;
	int	i;

	s = 1;
	i = 0;
	if (str[i] == '-')
	{
		s = s * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10 + (str[i++] - '0');
	fd->hex = 0;
	if (str[i] && str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')
		hex_color(str, i, fd);
	return ((s * r));
}

t_fdf	*ft_lstnew(char *content)
{
	t_fdf	*head;

	head = (t_fdf *)malloc(sizeof(t_fdf));
	if (!head)
		return (0);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_fdf **alst, t_fdf *new)
{
	if (!new)
		return ;
	if (! *alst)
	{
		*alst = new;
		return ;
	}
	ft_lstlast(*alst)->next = new;
}

t_fdf	*ft_lstlast(t_fdf *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (0);
}
