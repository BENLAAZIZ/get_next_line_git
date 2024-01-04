#include "get_next_line.h" 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{

	int fd = open ("text.txt", O_RDWR);

	printf("%s", get_next_line(fd));
	return (0);
	
}