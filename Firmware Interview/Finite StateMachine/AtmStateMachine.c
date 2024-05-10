// intution: We can use enumerations here as we our states and transitions can be represented as integers. We can make an enum for states and one for transitions
// then in our state machine we can basically take in the initial state as a pointer and the transition we are applying. then in our state machine we 
// can have a switch case where based on the state we can check if we have the correct transition, if so then change our current state to the next state

// justification: used pointers instead of simple state returns as I thought it would be a more realistic approach as we would want to store the current state somewhere for future use.
// however then the functions that I've made can be turned into void outputs as there is no need for the state machine to return the current state if the current state is always being updated


#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

typedef enum 
{
    IDLE,
    CARD_INSERTED,
    PIN_ENTERED,
    OPTION_SELECTED,
    AMOUNT_ENTERED
    
}AtmStates;

typedef enum
{
    INSERT_CARD,
    ENTER_PIN,
    SELECT_OPTION,
    ENTER_AMOUNT,
    MONEY_DISPATCHED
}AtmTransitions;

// Event Handlers 
static void  transition1(AtmStates *currentState){
    *currentState = CARD_INSERTED;
}

static void transition2(AtmStates *currentState){
    *currentState = PIN_ENTERED;    
}

static void transition3(AtmStates *currentState){
    *currentState = OPTION_SELECTED;
}

static void transition4(AtmStates *currentState){
    *currentState = AMOUNT_ENTERED;
}

static void transition5(AtmStates *currentState){
    *currentState = IDLE;
}

static void AtmStateMachine (AtmStates *currentState, AtmTransitions transition){
    switch(*currentState){
        case IDLE:
        if(transition == INSERT_CARD){
            transition1(currentState);
        }
        case CARD_INSERTED:
        if(transition == ENTER_PIN){
            transition2(currentState);
        }
        case PIN_ENTERED:
        if(transition == SELECT_OPTION){
            transition3(currentState);
        }
        case OPTION_SELECTED:
        if(transition == ENTER_AMOUNT){
            transition4(currentState);
        }
        case AMOUNT_ENTERED:
        if(transition == MONEY_DISPATCHED){
            transition5(currentState);
        } 
        default:
        printf("invalid operation");
    }
}

// int main(){

//     AtmStates currentState = IDLE;
//     assert(AtmStateMachine(&currentState, INSERT_CARD) == CARD_INSERTED);
//     assert(AtmStateMachine(&currentState, ENTER_PIN) == PIN_ENTERED);
//     assert(AtmStateMachine(&currentState, SELECT_OPTION) == OPTION_SELECTED);
//     assert(AtmStateMachine(&currentState, ENTER_AMOUNT) == AMOUNT_ENTERED);
//     assert(AtmStateMachine(&currentState, MONEY_DISPATCHED) == IDLE);
// }

// updated

int main(){

    AtmStates currentState = IDLE;

    char input; 

    AtmStateMachine(&currentState, INSERT_CARD); 
    assert(currentState == CARD_INSERTED);
    
    AtmStateMachine(&currentState, ENTER_PIN);
    assert( currentState == PIN_ENTERED);

    AtmStateMachine(&currentState, SELECT_OPTION);
    assert(currentState == OPTION_SELECTED);

    AtmStateMachine(&currentState, ENTER_AMOUNT);
    assert(currentState == AMOUNT_ENTERED);

    AtmStateMachine(&currentState, MONEY_DISPATCHED);
    assert(currentState == IDLE);

    // for continuous realistic usage

    while (true){
        printf("Current State %d \n", currentState);

        printf("please enter event\n0 = INSERT_CARD\n1 = ENTER_PIN\n2 = SELECT_OPTION\n3 = ENTER_AMOUNT\n4 = MONEY_DISPATCHED\n");
        input = getchar();
        AtmStateMachine(&currentState, atoi(&input));

    }

    
}
