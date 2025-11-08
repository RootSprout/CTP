#include<stdio.h>
#include<string.h>

void xor(char* temp, char* divisor, int len_divisor, int start){
    for(int i =0; i<len_divisor; i++){
        temp[start+i] = (temp[start+i] == divisor[i]) ? '0' : '1';
    }
}


void compute_crc(char* data, char* divisor, char* remainder){

    int len_data = strlen(data);
    int len_divisor = strlen(divisor);

    char temp[100];

    //copy current data to temp
    strcpy(temp, data);

    //append n-1 divisor 0 bits to data
    for(int i =0; i<len_divisor-1; i++){
        strcat(temp, '0');
    }

    int n = strlen(temp);
    //apply the xor for len of divisor = len of dividend
    for(int i= 0; i<= n- len_divisor; i++){
        if(temp[i] == '1'){
            //only do the xor when temp starts with 1
            xor(temp, divisor, len_divisor,i);
        }
    }

    strncpy(remainder, &temp[n- (len_divisor-1)], len_divisor-1);
    remainder[len_divisor - 1] = '\0';
}