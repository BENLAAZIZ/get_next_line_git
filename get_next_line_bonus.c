/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:06:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/11 19:47:13 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	size_t	i;
	char	*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	substr_len = len;
	if (start + substr_len > s_len) 
		substr_len = s_len - start;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < substr_len) 
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[substr_len] = '\0';
	return (substr);
}

static int	chek_new_line(char *buf, int *n)
{
	int	i;
	i = 0;
	if(!buf)
		return 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*n = i;
			return (1);
		}
		i++;
		*n = i;
	}
	return (0);
}


static char	*read_function(char **buf, char *buf_save, int n ,int fd)
{
	int			nb_read;
	char		*tmp;

	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, *buf, BUFFER_SIZE);
		if (nb_read == 0 && buf_save == 0)
			return (free(*buf) , *buf = NULL, NULL);
		if (nb_read == 0)
			break ;
		if (nb_read < 0)
			return (free(buf_save), free(*buf), buf_save = NULL, *buf = NULL, NULL);
		(*buf)[nb_read] = '\0';
		tmp = buf_save;
		buf_save = ft_strjoin(buf_save, *buf);
		if (buf_save == NULL)
			return (free(tmp),free(*buf), NULL);
		free(tmp);
		if (chek_new_line(*buf, &n))
			break ;
	}
	return (buf_save);
}

static char *free_function(char **buf_save, int fd, char **buf)
{
		if(fd > 0 && fd < 10240)
		{
			free(buf_save[fd]);
			buf_save[fd] = 0;
		}
		return (free(*buf), *buf = NULL, NULL);
}
char	*get_next_line(int fd)
{
	char		*buf;
	char static	*buf_save[10240];
	char		*line;
	int			n;
	char		*tmp;

	n = 0;
	line = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	//puts("hgsgn");
	if (buf == 0 || fd < 0 || read(fd,buf,0) < 0)
	{
		return (free_function(buf_save, fd, &buf));
		// if(fd > 0 && fd < 10240)
		// {
		// 	free(buf_save[fd]);
		// 	buf_save[fd] = 0;
		// }
		// return (free(buf), NULL);
	}
	buf_save[fd] = read_function(&buf, buf_save[fd], n, fd);
	if (buf_save[fd])
		free(buf);
	chek_new_line(buf_save[fd], &n);
	line = ft_substr(buf_save[fd], 0, n + 1);
	if (line == NULL)
		return (free(buf_save[fd]), buf_save[fd] = 0, NULL);
	tmp = buf_save[fd];
	if (buf_save[fd] != NULL)
		buf_save[fd] = ft_substr(buf_save[fd], n + 1, ft_strlen(buf_save[fd]));
	free(tmp);
	tmp = NULL;
    return line;
}
