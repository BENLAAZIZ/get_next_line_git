/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:14 by hben-laz          #+#    #+#             */
/*   Updated: 2023/12/14 17:55:17 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 // Adjust the buffer size as needed

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line = (char *)malloc(BUFFER_SIZE + 1);
    if (line == NULL) {
        perror("Error allocating memory");
        close(fd);
        return 1;
    }

    ssize_t bytesRead;
    int i = 0;

    while ((bytesRead = read(fd, &line[i], 1)) > 0) {
        if (line[i] == '\n') {
            line[i + 1] = '\0'; // Terminate the line with null character
            printf("Line: %s\n", line);
            i = 0; // Reset index for the next line
        } else {
            i++;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading file");
        free(line);
        close(fd);
        return 1;
    }

    free(line);
    close(fd);
    return 0;
}