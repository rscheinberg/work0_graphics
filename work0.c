#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
	
	//create image file
	int fd = open("image.ppm", O_CREAT | O_WRONLY | O_EXCL, 0644);
	
	//create file headers
	char *header = "P3 500 500 255 ";
	write(fd, header, strlen(header));
	
	//make a random image
	for(int i = 0; i < 500; i++) {
		for(int j = 0; j < 500; j++) {
			char buf[13];
			sprintf(buf, "%d %d %d ", j/2, i/2 , (j + i)/4);
			write(fd, buf, strlen(buf));
		}
	}
	
	//close image file
	close(fd);
	
}