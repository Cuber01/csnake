#ifndef __CYCLIC_BUFFER
#define __CYCLIC_BUFFER

#include <stdint.h>
#include <stdbool.h>

#ifdef UNIT_TESTS

    #define CBUFFER_TYPE uint8_t
    #define CB_BUFFER_SIZE 6

#else

    #include "main.h"
    #define CBUFFER_TYPE point_t
    #define CB_BUFFER_SIZE 1900

#endif


typedef struct
{
    uint32_t head_index;
    uint32_t tail_index;
} buffer_state_t;


typedef enum
{
    RV_SUCCESS = 0,
    RV_ERROR = 0xFFFF
    
} return_t;

#ifdef UNIT_TESTS
    void cb_dump(void);
#endif

void cbClear(void);

return_t cbAdd(CBUFFER_TYPE value);
return_t cbDel(void);

CBUFFER_TYPE cbGetHead(void);

void cbIterateReset(void);
int cbIterateGet(CBUFFER_TYPE *value_ref);

#endif
