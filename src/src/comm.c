#include<stdio.h>
#include<unistd.h>
#include "../include/packet.h"
#include "../include/comm.h"

void send_frame(int fd, frame_t *f){
    ssize_t bytes_written = write(fd, f, sizeof(*f));
    if(bytes_written > 0){
        printf("Sender: Data sent successfully!\n");
    }else{
        printf("Sender: Error Sending data\n");
    }
}

int receive_frame(int fd, frame_t *f){
    uint8_t byte;

    while(read(fd, &byte, 1) == 1){ //read preamble
        if(byte == 0xAA){
            f->preamble = byte;
            read(fd, (uint8_t*)f+1, sizeof(*f)-1);
            printf("Receiver: Message Read Successfully\n");
            return 1;
        }
    }

    printf("Receiver: Error Reading file\n");
    return 0;
}


