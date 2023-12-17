/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:56:37 by hben-laz          #+#    #+#             */
/*   Updated: 2023/12/17 14:27:25 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *buffer)
{
	int i = 0;
	while (buffer[i])
		i++;
		return (i);
}
char	*get_next_line(int fd)
{
	static char	buffer[1000];
	static char	*line;
	int			i = 0;
	

	size_t	byte_buf = read(fd, buffer, 20);

	if (byte_buf == -1)
	{
		write(1, "nothing to read", 16);
		return NULL;
	}
	int a = ft_strlen(buffer);
	line = malloc(a + 1);

	while (i < a)
	{
		line[i] = buffer[i];
		i++;
 	}
	
	return(line);
}
