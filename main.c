#include "get_next_line.h" 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

	int fd = open ("text.txt", O_RDWR);
	// int c;
	// while ((c = read(fd, buffer, 1000) != 0 && buffer[i] != '\n'))
	// 	i++;
	
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	
}