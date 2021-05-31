#include "stdafx.h"
#include "LIFO_Buf.h"
#include <stdlib.h>

LB_Status s = LB_NO_ERROR;

int main(void) {
	uint32_t i=0;
	uint8_t t;
	//LB_Status s = LB_NO_ERROR;
	// allocate a memory space for LIFO Buffer dynamically
	LIFO_BUF_t  lbuf;
	lbuf.length = 3;
	lbuf.base = (uint8_t*) malloc(sizeof(uint8_t) * lbuf.length);
	lbuf.head = lbuf.base; // the base and the head have the same address at first

	while (s != LB_FULL) {
		s = LIFO_buf_add_item(&lbuf, i);
		i++;
	}
	printf("the LIFO buffer is full! and the final address is %p: \n", lbuf.head);
	i = lbuf.length;

	while (s != LB_EMPTY) {
		t = LIFO_buf_pop_item(&lbuf);
		printf("the address of the item numer %d is %p and the its value is %d \n", i, lbuf.head, t);
		i--;
	}
	return 0;
}