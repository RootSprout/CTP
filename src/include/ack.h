#pragma once

void send_ack(int fd, uint16_t seq_no, int success);
int wait_for_ack(int fd, uint16_t expected_seq);