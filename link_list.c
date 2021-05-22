//#include "stdint.h"
#include "stdlib.h"
#include "link_list.h"

struct node* create_node(uint8_t Local_u8Value){
    struct node *pNewNode = malloc(sizeof(struct node));
    pNewNode->value = Local_u8Value;
    pNewNode->pNextNode = NULL;
    return pNewNode;
}

struct node** return_last_node_add(struct node *pFirst){
    while(pFirst->pNextNode != NULL){
        /*recursive*/
        (void)return_last_node_add(pFirst->pNextNode);
    }
    return &(pFirst->pNextNode);
}

struct node** return_node_add(struct node *pFirst, uint8_t Local_u8NodeNum){
    static uint8_t Local_u8Counter = 1; /*starting from first node*/
    while(pFirst->pNextNode != NULL && Local_u8Counter != Local_u8NodeNum){
        /*recursive*/
        (void)return_node_add(pFirst->pNextNode,Local_u8NodeNum);
        Local_u8Counter++;
    }
    Local_u8Counter = 1;
    return &(pFirst->pNextNode);
}

void add_node(struct node **pFirst, struct node **pNewNode, uint8_t Local_u8NodePosition){
    /*Starting the list, First Node*/
    if(Local_u8NodePosition == 1 && (*pFirst) == NULL){
        (*pFirst) = *pNewNode;
    }
    /*Second Node*/
    else if(((*pFirst)->pNextNode == NULL)){
        (*pFirst)->pNextNode = *pNewNode;
    }
    /*Adding node to any position*/
    else{
        struct node **pPreNode = return_node_add(*pFirst, Local_u8NodePosition-1);
        (*pNewNode)->pNextNode = (*pPreNode)->pNextNode;
        (*pPreNode)->pNextNode = *pNewNode;
    }
}

void add_node_to_end(struct node *pFirst, struct node *pNewNode){
    struct node **pLastNode = return_last_node_add(pFirst);
    (*pLastNode)->pNextNode = pNewNode;
}

void remove_node(struct node *pFirst, uint8_t Local_u8NodePosition){
    struct node **pPreNode = return_node_add(pFirst, Local_u8NodePosition-1);
    struct node **pCurrNode = return_node_add(pFirst, Local_u8NodePosition);
    (*pPreNode)->pNextNode = (*pCurrNode)->pNextNode;
    free(*pCurrNode);
}
