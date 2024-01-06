/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:13:50 by hben-laz          #+#    #+#             */
/*   Updated: 2024/01/06 18:03:59 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chek_new_line(char *buf, int *n)
{
	int	i;

	i = 0;
	n = &i;
	if (buf == NULL)
		return 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	n = &i;
	return (i);
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


char	*get_next_line(int fd)
{
	char static	*buf;
	char		*buf_save;
	char		*line;
	static int	n;
	static int	nb_read;
	
    
	n = 0;
	line = NULL;
	if (fd == -1 || (buf = (char *)malloc(BUFFER_SIZE + 1)) < 0)
		return NULL;
    while ((nb_read = read(fd, buf, BUFFER_SIZE)) > 0)
    {
		buf[BUFFER_SIZE] = '\0';
		if (chek_new_line(buf, &n))
			break ;
		buf_save = ft_strdup(buf);
		line = ft_strjoin(line, buf_save);
		free(buf_save);
    }
	if (nb_read < 0)
		return (NULL);
	buf_save = ft_strdup(buf);
	line = ft_strjoin(line, buf_save);
	free(buf_save);
	free(buf);

    return line;
}
