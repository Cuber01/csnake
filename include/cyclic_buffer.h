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

typedef struct {
    uint32_t head_index;
    uint32_t tail_index;    
} buffer_state_t;

typedef enum {
    RV_SUCCESS = 0,
    RV_ERROR   = 0xFFFF
} return_t;

#ifdef UNIT_TESTS
void cb_dump( void );
#endif

void cb_clear( void );
return_t cb_add( CBUFFER_TYPE value );
return_t cb_del( void );
CBUFFER_TYPE cb_get_head( void );
void cb_iterate_reset( void );
int cb_iterate_get( CBUFFER_TYPE* value_ref );


#endif
// en of file ---