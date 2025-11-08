#include<stdio.h>
#include<unistd.h>
#include "../../include/packet.h"

void send_frame(int fd, frame_t *f){
    ssize_t bytes_written = (fd, f, sizeof(*f));
    if(bytes_written > 0){
        printf("Data sent successfully!");
    }else{
        printf("Error Sending data");
    }
}




