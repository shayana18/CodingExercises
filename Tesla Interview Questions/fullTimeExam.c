#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "stdint.h"
#include "stdbool.h"
////////////////////////////////////////////////////////////////////////////////
// 1) Macro (10 points)
//    Create a macro (named C_TO_F) to convert from degrees Celsius to Fahrenheit
//    Macro should work for integer or floating point types
//    Note: degF = degC * (9/5) + 32

////////////////////////////////////////////////////////////////////////////////
// 2) Bit Manipulation (5 points)
//    Write a function that inverts (0 -> 1 or 1 -> 0) the most significant and
//    least significant bits of the data value pointed to by b.

////////////////////////////////////////////////////////////////////////////////
// 3) Debugging (5 points)
//    The function computeSquareADC() has not been producing correct
//    output consistently. Please describe all issues with the function.

void flip_hi_lo(uint8_t* b)
{
    *b ^= 0b10000001;

    // a more robust implementation if not given the integer size would be 

    // uint8_t shifts_for_most_sig = sizeof(*b) * 8 - 1; 

    // *b = ((*b ^ 1) | (*b ^ (1 << shifts_for_most_sig))); 
}

#define C_TO_F(degC) ((degC) * 9.0f / 5.0f + 32)

////////////////////////////////////////////////////////////////////////////////
// 4) Memory dump (10 points)
//    The following memory dump was taken while debugging an issue.
//
// Memory Dump:
// Address:  Byte:
// 0x1000    0xA0
// 0x1001    0x0A
// 0x1002    0xBA
// 0x1003    0x48
// 0x1004    0x2C
// 0x1005    0xB7
// 0x1006    0x3B
// 0x1007    0x82
// 0x1008    0x9C
// 0x1009    0xE5
// 0x100A    0x17
// 0x100B    0x40
// 0x100C    0xEF
// 0x100D    0x47
// 0x100E    0x0F
// 0x100F    0x98
// 0x1010    0x6F
// 0x1011    0xD5
// 0x1012    0x70
// 0x1013    0x9E
// 0x1014    0x94
// 0x1015    0x99
// 0x1016    0x4A
// 0x1017    0xBA
// 0x1018    0xCA
// 0x1019    0xB2
// 0x101A    0x32
// 0x101B    0xE6
// 0x101C    0x8E
// 0x101D    0xB9
// 0x101E    0xC5
// 0x101F    0x2E
// 0x1020    0xC3
//
// System is 32-bit, little-endian.
// A variable called myPacket is of type packet_S (typedef below).
// (Default compiler options; unpacked, naturally aligned.) -->This means padding and no packing 
// The address of myPacket is 0x1010.
//
typedef struct
{
    uint8_t count;
    uint16_t data[2]; 
    uint32_t timestamp;
} packet_S;

// a) What are the values of each member of myPacket?

// little-endian means the least significant byte takes the lower position in memory. so think of a uint32 -------- is more significant than 11111111in --------11111111
// big endian means the most significant bit takes the lower position in memory 
// since there is padding and we have a 32-bit processor each word of a processor is 4 bytes thus memory allocation is as follows:

// count: 0x6F
// data[0] : 0x9994 --because 0x94 is where the lower byte is however the lower byte in writing is the right most expressed byte 
// data[1] 0xBA4A
// timestamp: 0xE632B2CA

// LITTLE ENDIAN AND BIG ENDIAN ONLY APPLY TO THE BYTES OF A SPECFIC THING WE ARE LOOKING AT SO AN INDIVIDUAL ARRAY INDEX OR AN INT OR CHAR
// SO IF IT WAS A STRUCT THE ENTIRE STRUCT WOULD BE PLACED IN MEMORY AND THE ITEMS OF THE STRUCT WOULD FOLLOW THEIR RESPECTIVE ORDER HOWEVER
// THE BYTES OF THE ITEMS WOULD FOLLOW LITTLE OR BIG ENDIAN AS SPECIFIED 

// b) If the system was big-endian, what would the values of each member of
//    myPacket be?

// count: 0x64
// data[0] : 0x9499
// data[1] 0x4ABA
// timestamp: 0xCAB232E6

//Easy way to do little endian is to do big endian and reverse 

////////////////////////////////////////////////////////////////////////////////
// 5) State Machine (20 points)
//
//    Complete the function below to implement the state machine shown in the
//    diagram below for an electronic gumball vending machine.
//     * The initial state of the state machine should be IDLE
//     * The function should output the current state of the state machine
//     * Unexpected or invalid input should not cause a state transition
//     * GENERIC_FAULT may be received in any state and should put the machine
//       into the FAULT state

typedef enum
{
    IDLE,
    READY,
    VENDING,
    FAULT
} state_E;

typedef enum
{
    COIN,
    COIN_RETURN,
    BUTTON,
    VEND_COMPLETE,
    GENERIC_FAULT
} input_E;

state_E generic_fault_handler(){
    return FAULT;
} // to provide scalability for further fault handling 


state_E stateMachine(state_E current_state, input_E state_transistion){
   switch (state_transistion)
   {
   case GENERIC_FAULT:
        return FAULT;
        break;

    case COIN:
    if(current_state == IDLE){
        return READY;
    }
    break; 

    case COIN_RETURN:
    if(current_state == READY){
        return IDLE;
    }
    break;

    case BUTTON:
    if(current_state == IDLE){
        return VENDING;
    }
    break;

    case VEND_COMPLETE:
    if(current_state == VENDING){
        return IDLE;
    }
    break;

    default:
        return IDLE;
        break;
   }

   return current_state;
}

////////////////////////////////////////////////////////////////////////////////
// 6) Unit Testing (10 points)
//    Write a unit test for validatePointerAndData that exercises all code paths
//    and branch conditions

// @param dataPtr - int32_t pointer to data to be used
//
// @return TRUE if pointer is non-NULL, data value is positive, non-zero and not
//         equal to the sentinel value 0x7FFFFFFF, FALSE otherwise
//
bool validatePointerAndData(int32_t* dataPtr)
{
    bool status = false;
    if ((dataPtr != NULL) &&
        (*dataPtr > 0)    &&
        (*dataPtr != 0x7FFFFFFF))
    {
        status = true;
    }
    return status;
}

//
// @return TRUE if all tests pass, FALSE otherwise
//
void test_validatePointerAndData(void)
{
    uint32_t input = -1; 
    assert(validatePointerAndData(NULL) == false); 
    assert(validatePointerAndData(input) == false); 
    input =  0x8FFFFFFF;
    assert(validatePointerAndData(input) == false); 
    return true;

}

int main(){
    // checking if it works for both ints and floats
    assert(C_TO_F(0) == 32.0f);
    assert(C_TO_F(0) == 32);
    assert(C_TO_F(2 - 2) == 32);
    assert(C_TO_F(2 - 2) == 32.0f);

    //baseline checks for math
    assert(C_TO_F(5) == 41);
    assert(C_TO_F(0-5) == 23);
    assert(C_TO_F(25.2) != 77.0f);
    assert(C_TO_F(25.2) != 77);

    uint8_t b = 0; 

    flip_hi_lo(&b);
    assert( b == 129);
    flip_hi_lo(&b);
    assert( b == 0);

    test_validatePointerAndData();


    return 0; 
}

