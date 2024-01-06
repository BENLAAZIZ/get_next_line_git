/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:57:19 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/04 18:30:02 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIT_NEXT_LINE_H
# define GIT_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif