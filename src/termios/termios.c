#include <termios.h>
#include<fcntl.h>


int setup_termios(char* port_name){
    int fd = open(port_name, O_RDWR | O_NOCTTY);

    struct termios tty;

    //current port setup
    tcgetattr(fd, &tty);

    //baud rate
    cfsetispeed(&tty, B9600);
    cfsetospeed(&tty, B9600);

    //character size - 8bits per character
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;

    tty.c_iflag = 0;
    tty.c_oflag = 0;
    tty.c_lflag = 0;

    tcsetattr(fd, TCSANOW, &tty);

    return fd;

}