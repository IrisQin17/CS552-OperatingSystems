#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>

#define IOCTL_KBD _IOW(0, 6, struct ioctl_kbd)

int main () {
	struct ioctl_kbd{
		char key;
	};

	struct ioctl_kbd keyboard;

  	int fd = open ("/proc/ioctl_test", O_RDONLY);
  	int cont = 1;
  	char pressedKeys[] = "";

	while(cont){
	  	ioctl (fd, IOCTL_KBD, &keyboard);
	  	char getchar= keyboard.key;
	  	if (getchar=='\n') {
		  	printf("\nExiting...");
		  	printf("\nCollect keys: %s\n", pressedKeys);
		  	cont = 0;		  
	  	}
	  	else{
		  	printf("\nuser level: %c\n",getchar);
		  	strncat(pressedKeys, &getchar, 1);
		  	
	  	}
  	}
  	return 0;
}