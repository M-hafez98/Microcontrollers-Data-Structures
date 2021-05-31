//#pragma once
#include <stdint.h>

// enum for indicating the circuilar buffer (CB) status
typedef enum {
	CB_NO_ERROR =0,
	CB_FULL,
	CB_NOT_FULL,
	CB_EMPTY,
	CB_NOT_EMPTY,
	CB_NULL
}CB_status_t;

extern CB_status_t s; // global variable "s" declaration

// struct for CB data tracking
typedef struct {
	uint32_t length;
	uint8_t count;
	uint8_t* base; // the pointer that pointes to the starting point of the buffer
	uint8_t* tail; // the pointer that points to the oldest added item
	uint8_t* head; // the pointer that points to the newest added item
}FIFO_buf_t;

// CB functions prototypes
CB_status_t FIFO_buf_is_full(FIFO_buf_t*);
CB_status_t FIFO_buf_is_empty(FIFO_buf_t*);
CB_status_t FIFO_buf_add_item(FIFO_buf_t*, uint8_t);
uint8_t FIFO_buf_pop_item(FIFO_buf_t*);


