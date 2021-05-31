#include "stdafx.h"
#include "FIFO_buf.h"
#include <stdlib.h>

// global variable "s" definition
CB_status_e s = CB_NO_ERROR;

int main(void) {
	// local variables definition and declaration
	uint8_t i = 0;
	uint8_t t;
	FIFO_buf_t cb;
	cb.length = 3; // set the buffer length
	cb.base = (uint8_t*)malloc(sizeof(uint8_t) * cb.length); // allocate a memory size for FIFO Buffer
	cb.tail = cb.base;
	cb.head = cb.base;
	// adding elements to the buffer
	while (s != CB_FULL) {
		s = FIFO_buf_add_item(&cb, i);
		i++;
	}
	// print function for debugging purposes
	printf("the CB buffer is full and the end address is: %p \n", cb.head);
	i = 1;
	// poping the elements out from the buffer
	while (s != CB_EMPTY) {
		t = FIFO_buf_pop_item(&cb);
		printf("the element number %d is %d\n", i, t);
		i++;
	}

	return 0;
}