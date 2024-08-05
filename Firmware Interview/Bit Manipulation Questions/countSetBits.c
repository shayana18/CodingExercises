// Write an efficient program to count the number of 1s in the binary representation of an integer.


#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include <assert.h>

int countSetBits(int input){
    int count = 0; 
    while(input > 0){
        (input & 1) == 1 ? count++: (void)0; 
        input >>= 1; 
    }
    return count; 
}

int main(){
    assert(countSetBits(6) == 2);
    printf("test passed\n");
    assert(countSetBits(7) == 3);
    printf("test passed\n");
    assert(countSetBits(1124) == 4);
    printf("test passed\n");
    

}