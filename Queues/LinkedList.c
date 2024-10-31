// learning how to create linked lists in C 

// linked lists allow us to work with an array type storage structure but make its sie maluable in an efficent manner
// the problem with arrays is changing their size is difficult and further more adding to the middle of them is very difficult 


// each element in a Linked List are nodes 
// the first element in a linked list is a head 
// last element is a tail 
// the good thing about linked lists is that they do not need to  squash all the elements in the linked list in the same memory block like we do in arrays
// these elements can be anywhere in memory, we just link them 
// this linking also makes it easy to add stuff to the list as we would just link the previous last element to a new last element 

#include <stdlib.h> 
#include <stdio.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node_t; 

void printlist(node_t *head){
    node_t *temp_ptr = head; 

    while(temp_ptr != NULL){
        printf("%d", temp_ptr->value);
        temp_ptr = temp_ptr->next;
    }
}

node_t* reversingLinkedlist(node_t *head){

    node_t *curr = head;
    node_t *prev = NULL;
    node_t *next; 
   
   while(curr != NULL){

    next = curr->next;
    curr->next = prev; 

    prev = curr;
    curr = next; 
    }
    return prev;
}

int main(){
    node_t n1, n2, n3;
    node_t *head; 


    // assigning nodes their values 
    n1.value = 45; 
    n2.value = 8; 
    n3.value = 32;

    head = &n1; 
    n3.next = NULL; 
    n2.next = &n3; 
    n1.next = &n2; // this is how we define the last node

    // lets say we want to add another node in the end 
    node_t n4; 
    
    n4.value= 10;
    n4.next = NULL;
    n3.next = &n4;

    // now say we want to add n5 to the middle between n3 and n2 

    node_t n5= {.value= -1, .next = &n3};

    n2.next = &n5; 

    // if we want to remove the first node and adjust the list
    head= &n2; 



    printlist(head);

    printf("/n");
    printlist(reversingLinkedlist(head));



    return 0; 

}