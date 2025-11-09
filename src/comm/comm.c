#include<stdio.h>
#include<unistd.h>
#include "../../include/packet.h"

void send_frame(int fd, frame_t *f){
    ssize_t bytes_written = write(fd, f, sizeof(*f));
    if(bytes_written > 0){
        printf("Data sent successfully!");
    }else{
        printf("Error Sending data");
    }
}

int receive_frame(int fd, frame_t *f){
    uint8_t byte;

    while(read(fd, &byte, 1) == 1){ //read preamble
        if(byte == 0xAA){
            f->preamble = byte;
            read(fd, (uint8_t*)f+1, sizeof(*f)-1);
            printf("File Read Successfully");
            return 1;
        }
    }

    printf("Error Reading file");
    return 0;
}


