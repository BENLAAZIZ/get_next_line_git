/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:06:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/08 23:45:06 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	chek_new_line(char *buf, int *n)
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

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}
void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*c;
	size_t			i;

	i = 0;
	if (n == 0)
		return (dst);
	ptr = (unsigned char *)dst;
	c = (unsigned char *)src;
	if (ptr == NULL && c == NULL)
		return (dst);
	while (i < n)
	{
		*(ptr + i) = *(c + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tab;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	if (size > 0)
		ft_memcpy(tab, s1, size);
	tab[size] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)); 
	if (tab == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
		substr_len = s_len - start + 1;
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
char	*read_function(int nb_read, char **buf, char **buf_save, char *tmp, int n ,int fd)
{
	while (nb_read > 0)
	{
		nb_read = read(fd, *buf, BUFFER_SIZE);
		if (nb_read == 0 && *buf_save == 0)
			return (free (*buf) ,*buf = NULL,NULL);
		if (nb_read == 0)
			break ;
		if (nb_read < 0)
			return (free(*buf_save), free(*buf), *buf_save = 0,*buf = NULL, NULL);
		*buf[nb_read] = '\0';
		tmp = *buf_save;
		*buf_save = ft_strjoin(*buf_save,*buf);
		free(tmp);
		if (chek_new_line(*buf, &n))
			break ;
	}
	return *buf_save;
}

char	*get_next_line(int fd)
{
	char		*buf;
	char static	*buf_save;
	char		*tmp;
	char		*line;
	int			n;
	int			nb_read;

	n = 0;
	line = NULL;
	nb_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (free(buf_save), buf_save = 0, NULL);
	buf_save = read_function(nb_read, &buf, &buf_save, tmp, n, fd);
	free (buf);
	chek_new_line(buf_save, &n);
	line = ft_substr(buf_save,0,n+1);
	tmp = buf_save;
	buf_save = ft_substr(buf_save,n+1,ft_strlen(buf_save));
	puts("rrrrrrr");
	free (tmp);
	tmp = NULL;
	return (line);
}
