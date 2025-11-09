#pragma once

void compute_crc(char* data, char* divisor, char* remainder);
void xor(char* temp, char* divisor, int len_divisor, int start);
void string_to_bits(char* message, char* output);