// Write a program to print Binary representation of a given number N.

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "assert.h"

void binaryRepresentation(uint32_t input){
    for(uint32_t i = 1 << 31; i > 0; i >>= 1){
        (input & i) == 0?  printf("0"): printf("1");
    }
    printf("\n");
}

int main(){
    binaryRepresentation(7);
    binaryRepresentation(1124);
    return 0; 
}