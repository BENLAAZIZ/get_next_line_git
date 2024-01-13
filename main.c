/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:50 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/13 19:01:51 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	//read from multipl files
	
	// int fd1 = open("file1.txt" , O_CREAT | O_RDONLY);
	// int fd2 = open("file2.txt",O_CREAT | O_RDONLY);
	// int fd3 = open("file3.txt",O_CREAT | O_RDONLY);
	// int i = 0;
	// char *s;
	// while((s = get_next_line(3 + i % 3)))
	// {
	// 	puts(s);
	// 	free(s);
	// 	i++;
	// }

	//write and read
	char *str = "hug";
	int fd = open("fil.txt", O_CREAT | O_RDWR);
	while (1)
	{
		str = get_next_line(0);
		write(fd, str, strlen(str));
	
	}
	{
		/* code */
	}
	
	return (0);
}