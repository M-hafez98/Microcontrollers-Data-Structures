// Linked-Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdlib.h"
#include "link_list.h"

int main(void)
{
    struct node *pFirstNode = NULL;
    struct node *pN1, *pN2, *pN3, *pN4;
    /*Nodes Creation*/
    pN1 = create_node(100);
    pN2 = create_node(200);
    pN3 = create_node(150);
    pN4 = create_node(40);
    /*List Creation*/
    add_node(&pFirstNode, &pN1, 1);
    add_node(&pFirstNode, &pN2, 2);
    add_node(&pFirstNode, &pN3, 3);
    add_node(&pFirstNode, &pN4, 3);
    remove_node(pFirstNode, 4);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
