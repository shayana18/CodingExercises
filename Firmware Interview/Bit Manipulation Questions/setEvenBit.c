#include "stdint.h"
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"

// Set Even-Positioned Bits (5 points)
// Write a function that sets to 1 all the even-positioned bits of the data value pointed to by b (bit positions 2, 4, 6, and 8).

uint8_t setEvenBitInt(uint8_t input){
    input |= 0b10101010;
    return input;
}

// void setEvenBitInt( uint8_t *input){
//     int total_shifts = sizeof(*input) * 8 / 2; 

//     uint8_t bit_mask = 1; 

//     for(int i = 0; i < total_shifts; i++){
//         bit_mask |= (1 << 2); 
//     }
//     *input |= bit_mask;  
// }

int main(){
    uint8_t input = 0b10101010; 
    printf("input = %d \noutput= %d\n", input, setEvenBitInt(input));
    input = 10;
    printf("input = %d \noutput= %d\n", input, setEvenBitInt(input));
    input = 0;
    printf("input = %d \noutput= %d\n", input, setEvenBitInt(input));
    input = 255;
    printf("input = %d \noutput= %d\n", input, setEvenBitInt(input));

    return 0; 
}