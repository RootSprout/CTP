#include <stdio.h>
#include <stdint.h>
#include "../include/comm.h"
#include "../include/crc.h"
#include "../include/packet.h"
#include "../include/termios.h"
#include "../include/ack.h"
#include "../include/datalink.h"
#include <string.h>
#include <stdlib.h> 

int dsender(){
    int fd = setup_termios("/tmp/sender");

    uint16_t seq_no = 1;
    frame_t f;

    f.preamble = 0xAA;
    f.seq_no = 1;
    f.ack_no = 0;

    char message[] = "Hi";
    char divisor[] = "1101";
    char bit_string[1024];
    char remainder[32];

    string_to_bits(message, bit_string);
    compute_crc(bit_string, divisor, remainder);

    //final transmitted message
    char transmitted[1056];
    strcpy(transmitted, bit_string);
    strcat(transmitted, remainder);

    f.crc = (uint8_t)strtol(remainder, NULL, 2);
    strcpy((char*)f.data, message);

    send_frame(fd, &f);

        // wait for ACK
    printf("Checking for ACK\n");
    if (wait_for_ack(fd, seq_no) == 0) {
            printf("Sender: Resending frame %d\n...", seq_no);
            send_frame(fd, &f);
    }else{
        printf("Sender: Received ACK from Receiver\n");
    }

    seq_no++;

    return 0;

}

/*
On the receiver side,
do crc on the transmitted data and reaminder should be zero beacuse tranmitted should be exactly divided 
by the divisor now
*/





