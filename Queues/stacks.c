#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// implementing a stack using arrays in C is simple 
// THESE are FILO 

#define STACK_LENGTH 6
#define STACK_EMPTY -1
#define ERR_CODE_POP INT_MIN

int stack[STACK_LENGTH]; // initializing stack
int top = STACK_EMPTY; 

bool push(int val){
    if(top >= STACK_LENGTH - 1) return false; 

    top++; 
    stack[top] = val;
    return true; 
}

int pop(void){
    if(top <= STACK_EMPTY) return ERR_CODE_POP; 
    top--; 
    return stack[top+1]; 
}


// Now lets do it with linkedlists 

// 1. create the node struct



typedef struct node_t
{
    int val; 
    struct node_t *next;
}node_t;

//initialize some head

typedef node_t* stack_linkedList; // this helps us encapsulate, so we can have multiple stacks through linked lists as any time we want have a new one we just initialize a new stack type

// push function

bool push_linked(stack_linkedList *mystack,  int val){
    node_t *newnode = malloc(sizeof(node_t)); // why use DMA? we use dynamic memory allocation to allocate memory for the new node pointer to point to before initializing the struct it is pointing to 
    // why cant newnode be defined as a struct why a pointer to a struct, this is because of how scope works in C, if we want this to be persist outside of the function we need to understand that when primitive data types (structs, ints, floats, doubles etc)
    // are defined inside a function then it only holds value inside that function, when a pointer is used it assigns memory that can be accessed from anywhere 
    if(newnode == NULL) return false;

    newnode->val = val; 
    newnode->next = *mystack; 
    *mystack = newnode; // the reason this works is because the assumption that when a pointer is updated its previous usages are also updated is wrong 
    return true;
}

int pop_linked(stack_linkedList *mystack){
    if(*mystack == NULL) return ERR_CODE_POP;

    int result = (*mystack)->val;
    node_t* temp = *mystack; // points to the same memory address as head, if we dereferenced head then it would create a copy of what head points to (the struct) and point to where the copy is stored
    *mystack = (*mystack)->next;
    free(temp);
    return result;

}




int main(){

    // push(10);
    // push(20); 
    // push(30);
    // push(5);
    // push(0);

    // int out; 

    // while((out = pop())!= ERR_CODE){
    //     printf("%d\n", out);
    // }

    stack_linkedList s1 = NULL, s2 = NULL; 

    push_linked(&s1, 10);
    push_linked(&s1, 20); 
    push_linked(&s1, 30);
    push_linked(&s2, 5);
    push_linked(&s2, 0);

    int out; 

    while ((out = pop_linked(&s1)) != ERR_CODE_POP){
        printf("%d\n", out);
    }

    return 0; 
}