#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/include/comm.h"
#include "src/include/datalink.h"



int main(int argc, char *argv[]) {

    srand(time(NULL));

    if (argc >= 2) {
        int rate = atoi(argv[1]);
        set_loss_rate(rate);
        printf("Fault Injection Enabled: drop 1 in %d frames\n", rate);
    }

    dsender();
    return 0;
}
