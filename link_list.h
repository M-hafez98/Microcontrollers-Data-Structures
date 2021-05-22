#ifndef LINK_LIST_H
#define LINK_KIST_H

#include "stdint.h"

struct node {
	uint8_t value;
	struct node* pNextNode;
};

struct node* create_node(uint8_t);
struct node** return_last_node_add(struct node *pFirst);
struct node** return_node_add(struct node *pFirst, uint8_t Local_u8NodeNum);
void add_node(struct node **pFirst, struct node **pNewNode, uint8_t Local_u8NodePosition);
void remove_node(struct node*, uint8_t);


#endif
