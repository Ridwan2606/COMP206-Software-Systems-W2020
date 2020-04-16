//Author: Ridwan Kurmally
//Git Repository: https://github.com/Ridwan2606/COMP206-Software-Systems-W2020

#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main(int argc, char *argv[]) {
    struct Node x;
    head = NULL;
    add_node(5);
    printf("Head has element: %d\n", head->element);
    add_node(10);
    add_node(15);
    print_list();
}
