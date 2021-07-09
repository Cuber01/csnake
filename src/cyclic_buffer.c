#include <stdio.h>

#include "cyclic_buffer.h"
#include "main.h"

// actually its not cyclic

struct
{
    buffer_state_t state;
    CBUFFER_TYPE buffer[CB_BUFFER_SIZE];
} cyclic_buffer;

static int current_index;

#ifdef UNIT_TESTS

void cb_dump(void)
{

    //                            H     T
    //BUFFER: h: 3 t: 1 => 00 00 00 BB AA 00
    printf(white);
    printf("\r\nBUFFER: h: %d t: %d => ", cyclic_buffer.state.head_index, cyclic_buffer.state.tail_index);

    for (int i = CB_BUFFER_SIZE; i >= 0; i--)
    {

        if (i == cyclic_buffer.state.head_index)
        {
            printf(red);
            printf("%02X ", cyclic_buffer.buffer[i]);
        }
        else if (i == cyclic_buffer.state.tail_index)
        {
            printf(green);
            printf("%02X ", cyclic_buffer.buffer[i]);
        }
        else
        {
            printf(white);
            printf("%02X ", cyclic_buffer.buffer[i]);
        }
    }
    fflush(stdout);
}
#endif

// clears all from buffer
void cbClear(void)
{

    cyclic_buffer.state.head_index = 0;
    cyclic_buffer.state.tail_index = 0;

}

// add value to the head
return_t cbAdd(CBUFFER_TYPE value)
{

    cyclic_buffer.state.head_index++;
    cyclic_buffer.buffer[cyclic_buffer.state.head_index] = value;

    return RV_SUCCESS;

}

// delete value from tail
return_t cbDel(void)
{

    cyclic_buffer.state.tail_index++;

    return RV_SUCCESS;

}

void cb_iterate_reset(void)
{
    current_index = cyclic_buffer.state.head_index;
}

int cb_iterate_get(CBUFFER_TYPE *value_ref)
{

    *value_ref = cyclic_buffer.buffer[current_index];

    current_index--;
    if (current_index == cyclic_buffer.state.tail_index)
    {
        return true;
    };

    return false;
}

CBUFFER_TYPE cb_get_head(void)
{
    return (cyclic_buffer.buffer[cyclic_buffer.state.head_index]);
}

CBUFFER_TYPE cb_get_tail(void)
{
    return (cyclic_buffer.buffer[cyclic_buffer.state.tail_index]);
}


