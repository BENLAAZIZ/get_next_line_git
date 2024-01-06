/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:35:53 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/06 18:05:00 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%s", get_next_line(fd));
	return (0);
}
