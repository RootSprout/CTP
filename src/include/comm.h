#pragma once

#include "packet.h"

void send_frame(int fd, frame_t *f);
int receive_frame(int fd, frame_t *f);
void set_loss_rate(int rate);
