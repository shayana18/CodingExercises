//  question: implement a simple traffic light. red--> green --> yellow--->|
//                                               ^                         |
//                                               |-------------------------|
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>

typedef enum{
RED,
YELLOW,
GREEN
} States; 


States redToGreenEventHandler(){
    return GREEN;
}

States GreenToYellowEventHandler(){
    return YELLOW;
}

States YellowToRedEventHandler(){
    return RED;
}


void finiteStateMachine(States *currentState){
while (1){
    switch (*currentState)
    {
    case RED:
        *currentState = redToGreenEventHandler();
        printf("Light is Green GOOOO!\n");
        fflush(stdout);
        sleep(5);
        break;

    case GREEN:
        *currentState = GreenToYellowEventHandler();
        printf("Light is Yellow SLOW DOWN!\n");
        fflush(stdout);
        sleep(2);
        break;
    
    case YELLOW:
        *currentState = YellowToRedEventHandler();
        printf("Light is RED STOP!\n");
        fflush(stdout);
        sleep(5);
        break;
    
    default:
        break;
    }
}
}

int main(){

    static States currentState = RED;

    finiteStateMachine(&currentState);

    return 0; 
}