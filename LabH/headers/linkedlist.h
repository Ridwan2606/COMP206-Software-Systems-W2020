//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

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
struct Node* head;

/*
Function to add a node as the new head to the linked list
*/
void add_node(int x);

/*
Function to print the linked list
*/
void print_list();