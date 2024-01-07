/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:40:16 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/07 16:36:18 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>


int main ()
{

	int		fd;
	fd = open("file.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
		return (0);
	char *c;
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);

	
	return (0);
}