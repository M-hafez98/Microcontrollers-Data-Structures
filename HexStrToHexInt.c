#include <stdlib.h>
#include <stdio.h>
#include <string>


int main(void) {
    const char hexstring[] = "2e0c29bf96b04be57b8784e53f2fbd07544662f92bfe1e37859b609cf6510243", *pos = hexstring;
    static uint8_t val[sizeof(hexstring)/2]; // variable array size is valid only in C99 and upper versions.
    size_t count;
  
     /* WARNING: no sanitization or error-checking whatsoever */
    for (count = 0; count < (sizeof(val)/sizeof(*val)); count++) {
        sscanf(pos, "%2hhx", &val[count]);
        pos += 2;
    }
    /*printing the array for testing*/
    for(count = 0; count < (sizeof(val)/sizeof(*val)); count++) {
        if(count == (sizeof(val)/sizeof(*val))-1) {
            printf("0x%02x ", val[count]);
        }
        else {
           printf("0x%02x, ", val[count]);
        }
    }
    printf("\n");

    return 0;
}
