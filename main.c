/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:50 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/18 22:29:58 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd = open("text.txt", O_RDWR | O_CREAT);
	char	*s = "dv";
	
	// while (1)
	// {
	// 	s = get_next_line(0);
	// 	write(fd, s, ft_strlen(s));
	// 	free(s);
	// }
	// while (s)
	// {
		
	// 	s = get_next_line(fd);
	// 	if (s == NULL)
	// 		break ;
	// 	puts(s);
	// 	free(s);
	// }

	write(fd ,"a\nb\nc\n", 6);
	s = get_next_line(fd);
	puts(s);
}