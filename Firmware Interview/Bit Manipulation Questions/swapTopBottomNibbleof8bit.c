(// practice problem: flip the top and bottom nibble of 

// intuition: take the most significant bit and bring it down to least signficant bit... AND this with 1 to see if it is set. place the value into least signifcant bit of output.
// shift right in the input and place but shifting up in output

#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

uint8_t swapNibble(uint8_t input){ 
    uint8_t output = (input << 4) | (input >> 4);
    return output;
}

int main(){
    printf("%d\n",swapNibble(10));
    return 0; 
})