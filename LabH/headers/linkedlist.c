//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>

/*
Declaration of a node from a linked list that stored an element
*/
struct Node {
    int element;
    struct Node* next;
};

/*
Head of Linked List
*/
struct Node* head = NULL;

/*
Function to add a node as the new head to the linked list
*/
void add_node(int x){
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new-> element = x; // *new.element = x;
    if (head == NULL){
        new -> next = NULL;
        head = new;
    } else {
        new -> next = head;
        head = new;
    }
}

/*
Function to print the linked list
*/
void print_list(){
    struct Node* tmp = head;
    while (tmp != NULL){
        printf("%d ", tmp->element);
        tmp = tmp -> next;
    }
    printf("\n");
}

/*
Function to delete the first node from the linked list
*/
void delete_first_node(){
    if (head != NULL){
        struct Node* first = head;
        head = head->next;
        free(first);
    }
}







