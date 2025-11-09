#include <stdio.h>
#include <stdint.h>
#include "../include/comm.h"
#include "../include/crc.h"
#include "../include/packet.h"
#include "../include/termios.h"
#include "../include/ack.h"
#include <string.h>
#include <stdlib.h> 
#include "../include/datalink.h"

int dreceiver(){

    int fd = setup_termios("/tmp/receiver");
    frame_t f;

    printf("Waiting for data...\n");
    
    receive_frame(fd, &f);

    //compute crc again and check
    char bitstring[1024], remainder[32];
    string_to_bits((char*)f.data, bitstring);
    char divisor[] = "1101"; // same as sender
    compute_crc(bitstring, divisor, remainder);

    int received_crc = (uint8_t)strtol(remainder, NULL, 2);

    if(received_crc == f.crc){
        printf("No Error in received data\n");
        printf("Receiver: Sending ACK For Received Data....\n");
        send_ack(fd, f.seq_no, 1);
        printf("Receiver: Sent ACK successfully");
    }else{
        send_ack(fd, f.seq_no, 0);
        printf("Error in Received Data");
    }

    return 0;
}