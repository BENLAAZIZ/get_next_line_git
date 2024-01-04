/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:56:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/03 19:36:49 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


// #ifndef BUFFER_SIZE 5
// #define BUFFER_SIZE 5
// #endif


// int ft_strlen(char *buffer)
// {
// 	int i = 0;
// 	while (buffer[i])
// 		i++;
// 		return (i);
// }
char	*get_next_line(int fd)
{
	char static	*buf;
	int char_read;
	char static *line;
	buf = malloc(5 * sizeof(char) + 1);
	char_read = read(fd, buf, 5);
	buf[6] = '\0';
	if (fd <= 0)
		return (0);
	return (buf);
}
