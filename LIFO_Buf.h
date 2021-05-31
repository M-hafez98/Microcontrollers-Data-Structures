#include <stdint.h>

// LIFO Buffer status
typedef enum {
	LB_NO_ERROR = 0,
	LB_FULL,
	LB_NOT_FULL,
	LB_EMPTY,
	LB_NOT_EMPTY,
	LB_NULL
}LB_Status;

extern LB_Status s;

// LIFO Buffer Definition
typedef struct {
	uint32_t length;
	uint8_t* base;
	uint8_t* head;
}LIFO_BUF_t;

// LIFO functions prototypes
LB_Status LIFO_buf_is_full(LIFO_BUF_t*);
LB_Status LIFO_buf_is_empty(LIFO_BUF_t*);
LB_Status LIFO_buf_add_item(LIFO_BUF_t* , uint8_t);
uint8_t LIFO_buf_pop_item(LIFO_BUF_t*);



