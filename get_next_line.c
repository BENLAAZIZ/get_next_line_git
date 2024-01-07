/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:06:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/07 19:55:09 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	chek_new_line(char *buf, int *n)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			(*n)++;
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

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	if ((unsigned char)c == '\0' )
		return ((char *)(str + len));
	while (len >= 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)(str + len + 1));
		len--;
	}
	return (NULL);
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
		return (ft_strdup(""));
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

char	*get_next_line(int fd)
{
	char		*buf;
	char static	*buf_save;
	char		*line;
	int			n;
	int			nb_read;
	char		*tmp;

	n = 0;
	line = NULL;
	nb_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (free(buf_save), buf_save = 0, NULL);
    while (nb_read > 0)
    {
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == 0 && buf_save == 0)
			return (NULL);
		if (nb_read == 0)
			break ;
		if (nb_read < 0)
			return (free(buf_save), free(buf), buf_save = 0, NULL);
		buf[nb_read] = '\0';
		tmp = buf_save;
		buf_save = ft_strjoin(buf_save,buf);
		free(tmp);
		if (chek_new_line(buf, &n))
			break ;
    }
	free(buf);
	chek_new_line(buf_save, &n);
	line = malloc(n + 1);
	if (line == 0)
		return (free(buf_save), buf_save = 0, NULL);
	ft_memcpy(line, buf_save, n);
	line[n] = '\0';
	// stor after new linwe 
	if (chek_new_line(buf_save, &n) == 0)
		return(line);
	// nb_read = ft_strlen(buf_save) - n;
	
	// tmp = malloc(nb_read + 1);
	// if (tmp == 0)
	// 	return (NULL);
	// if (line == 0)
	// 	return (free(buf_save), buf_save = 0, NULL);
	// tmp = ft_strrchr(buf_save, '\n');
	// free(buf_save);
	// buf_save = malloc(nb_read + 1);
	// buf_save = ft_strdup(tmp);
	// // tmp[nb_read] = 0;
	// // ft_memcpy(tmp, buf_save + n, nb_read);
	// // buf_save = tmp;
	// free(tmp);
    return line;
}
