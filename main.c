#include <stdio.h>
#include <stdint.h>


#pragma pack(push, 1)
typedef struct frame
{
    uint8_t preamble; 
    uint16_t seq_no;
    uint16_t ack_no;
    uint8_t data[512];
    uint8_t checksum;

};
#pragma pack(pop)




