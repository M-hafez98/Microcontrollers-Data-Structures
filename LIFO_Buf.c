#include "stdafx.h"
#include "LIFO_Buf.h"


LB_Status LIFO_buf_is_full(LIFO_BUF_t* lb) {
	if (!lb || !lb->base || !lb->head) {
		return LB_NULL;
	}
	if (lb->head == (lb->base + lb->length-1)) { // (length -1) not length only
		return LB_FULL;
	}
	else {
		return LB_NOT_FULL;
	}
}

LB_Status LIFO_buf_is_empty(LIFO_BUF_t* lb) {
	if (!lb || !lb->base || !lb->head) {
		return LB_NULL;
	}
	if (lb->base != lb->head) {
		return LB_NOT_EMPTY;
	}
	else {
		return LB_EMPTY;
	}
}

LB_Status LIFO_buf_add_item(LIFO_BUF_t* lb, uint8_t item) {
	if (!lb || !lb->base || !lb->head) {
		return LB_NULL;
	}
	if (LIFO_buf_is_full(lb) == LB_FULL) {
		*(lb->head) = item;
		return LB_FULL;
	}
	*(lb->head++) = item;
	return LB_NO_ERROR;
}

uint8_t LIFO_buf_pop_item(LIFO_BUF_t* lb) {
	if (!lb || !lb->base || !lb->head) {
		return LB_NULL;
	}
	if (LIFO_buf_is_empty(lb) == LB_EMPTY) {
		s = LB_EMPTY;
		return *(lb->head);
	}
	return *(lb->head--);
}