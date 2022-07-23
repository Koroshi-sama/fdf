/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrazik <aerrazik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:49:34 by aerrazik          #+#    #+#             */
/*   Updated: 2022/07/23 02:02:20 by aerrazik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<limits.h>

int	ft_atoi(const char *str)
{
	unsigned long long	r;
	int					s;

	s = 1;
	if (*str == '-')
	{
		s = s * (-1);
		str++;
	}
	else if (*str == '+')
		str++;
	r = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
    
	return ((s * r));
}

// #include<stdio.h>
// #include<stdlib.h>
// int	main()
// {
// 	printf("%d\n",atoi("22,0xFFFFF"));
// 	printf("%d",ft_atoi("22,0xFFFFF"));
// 	return (0);
// }
