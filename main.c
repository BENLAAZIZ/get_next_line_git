/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:43:50 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/18 17:53:56 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>


int	main()
{
	//read from multipl files
	
	// int fd1 = open("file1.txt" , O_CREAT | O_RDONLY);
	// int fd2 = open("file2.txt",O_CREAT | O_RDONLY);
	// int fd3 = open("file3.txt",O_CREAT | O_RDONLY);
	// int i = 0;
	char *s = "ddjbd";
	// while((s = get_next_line(3 + i % 3)))
	// {
	// 	puts(s);
	// 	free(s);
	// 	i++;
	// }

	//write and read
	// char *str = "hug";
	// int fd = open("hamza.txt", O_CREAT | O_RDWR);
	// while (1)
	// {
	// 	str = get_next_line(0);
	// 	write(fd, str, strlen(str));
	
	// }
	// free(str);
	// str = NULL;
	// write(fd, "a\nb\nc\n", 6);
	// close(fd);
	// fd = open("fil.txt", O_CREAT | O_RDWR);
	// char *s = get_next_line(fd);
	// puts(s);
	
	// int	fd = open("file1.txt", O_RDWR | O_CREAT);
	// char *s = "fds";
	// while (s)
	// {
	// 	s = get_next_line(fd);
	// 	puts(s);
	// 	free(s);
	// }
	int fd;
	// fd = open("fil.txt", O_CREAT | O_RDWR);
	// write(fd, "a\n8\nc\n", 6);
	// close(fd);
	fd = open("fil.txt", O_CREAT | O_RDWR);
	while (s)
	{
	s = get_next_line(3);
	if (s == 0)
		break ;
	puts(s);
	free(s);
	}


	return (0);
}