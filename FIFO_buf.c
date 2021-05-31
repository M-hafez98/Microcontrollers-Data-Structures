#include "stdafx.h"
#include "FIFO_buf.h"

CB_status_t FIFO_buf_is_full(FIFO_buf_t* cb) {
	if (!cb || !cb->base || !cb->head || !cb->tail) {
		return CB_NULL;
	}
	if ( (cb->head == (cb->tail + cb->length -1)) || (cb->tail == cb->head + 1) ) {
		return CB_FULL;
	}
	else {
		return CB_NOT_FULL;
	}
}

CB_status_t FIFO_buf_is_empty(FIFO_buf_t* cb) {
	if (cb->tail == cb->head) {
		return CB_EMPTY;
	}
	else {
		return CB_NOT_EMPTY;
	}
}

CB_status_t FIFO_buf_add_item(FIFO_buf_t* cb, uint8_t item) {
	if (!cb || !cb->base || !cb->head || !cb->tail) {
		return CB_NULL;
	}
	if (FIFO_buf_is_full(cb) == CB_FULL) {
		return CB_FULL; // overridding is not permitted
	}
	// check if the head at the end of the buffer area
	if (cb->head == (cb->base + cb->length - 1)) {
		cb->head = cb->base;
	}
	
	else {
		cb->head++;
	}
	*(cb->head) = item;
	return CB_NO_ERROR;
}

uint8_t FIFO_buf_pop_item(FIFO_buf_t* cb) {
	if (!cb || !cb->base || !cb->head || !cb->tail) {
		return CB_NULL;
	}
	// check for empty buffer. If it is, pop the item and send the empty status enum
	if (FIFO_buf_is_empty(cb) == CB_EMPTY) {
		s = CB_EMPTY;
		return *(cb->tail);
	}
	// check if the tail at the end of the buffer area
	if (cb->tail == (cb->base + cb->length - 1)) {
		cb->tail = cb->base;
		// this method of dereferencing, in order not to define an intermidate variable to handel *(cb->tail)
		return *(cb->base + cb->length - 1);
	}
	else {
		return *(cb->tail++);
	}
	
}