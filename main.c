/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:40:16 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/11 17:29:36 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" 
#include <stdio.h>


int main ()
{

	int		fd;
	fd = open("fil.txt", O_RDONLY | O_CREAT);
	char *c;
	while((c = get_next_line(fd)))
	{
		printf("%s", c);
		free(c);
		c = NULL;
	}
	return (0);
}