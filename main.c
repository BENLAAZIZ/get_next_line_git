/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:50 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/18 23:15:50 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main()
{
	int		fd = open("file.txt", O_RDWR | O_CREAT);
	char	*s = "dv";
	
	// while (1)
	// {
	// 	s = get_next_line(0);
	// 	write(fd, s, ft_strlen(s));
	// 	free(s);
	// }
	while (s)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		puts(s);
		free(s);
	}

	// write(fd ,"a\nb\nc\n", 6);
	// close(fd);
	// fd = open("file.txt", O_RDWR | O_CREAT);
	// s = get_next_line(fd);
	// puts(s);
	// free(s);
	// s = get_next_line(fd);
	// puts(s);
	// free(s);
	// s = get_next_line(fd);
	// puts(s);
	// free(s);
}