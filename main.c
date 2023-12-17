/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:14 by hben-laz          #+#    #+#             */
/*   Updated: 2023/12/17 11:02:38 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	static char buffer[100];

	int fd = open("test.txt", O_RDONLY);
	 
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	size_t a = read(fd, buffer, sizeof(buffer));
	
	

    if (a == -1) 
	{
		perror("Error reading file");
		close(fd);
		exit(EXIT_FAILURE);
	}
	buffer[a] = '\0';
	printf("%d\n", fd);
    printf("Read %zd bytes from the file:\n%s\n", a, buffer);
	write(0, "tsxsjhx", fd);
	
	close(fd);
	return 0;
}