#include <stdio.h>


#include "cyclic_buffer.h"
#include "main.h"


struct {
    buffer_state_t state;
    CBUFFER_TYPE buffer[CB_BUFFER_SIZE];
} cyclic_buffer;


#ifdef UNIT_TESTS
// [x] prints buffer values
void cb_dump( void ){

    //                            H     T   
    //BUFFER: h: 3 t: 1 => 00 00 00 BB AA 00 
    printf(white);
    printf("\r\nBUFFER: h: %d t: %d => ", cyclic_buffer.state.head_index, cyclic_buffer.state.tail_index);
    
    for (int i = CB_BUFFER_SIZE; i>=0  ; i--) 
    {  
       

        if ( i == cyclic_buffer.state.head_index) {
            printf(red);
            printf("%02X ", cyclic_buffer.buffer[i] );
            
        } else if (i == cyclic_buffer.state.tail_index)
        {    
            printf(green);
            printf("%02X ", cyclic_buffer.buffer[i] );
            
        } else {
            printf(white);
            printf("%02X ", cyclic_buffer.buffer[i] );
        }
        
    }
    fflush(stdout); 

}
#endif

// clears all from buffer
void cb_clear( void ){

    cyclic_buffer.state.head_index = 0;
    cyclic_buffer.state.tail_index = 0;
     
    // for (int i = 0; i < CB_BUFFER_SIZE; i++) 
    // {
    //     cyclic_buffer.buffer[i] = 0;
    // }

}

// add value to the head
return_t cb_add( CBUFFER_TYPE value ){


    cyclic_buffer.state.head_index++;
    cyclic_buffer.buffer[cyclic_buffer.state.head_index] = value;
     
    return RV_SUCCESS;



    // for (int i = CB_BUFFER_SIZE-1; i > 0; i--) 
    // {
    //     if (cyclic_buffer.buffer[i] == 0); 
    //     {
    //         cyclic_buffer.buffer[i] = value;
    //         return RV_SUCCESS;
    //     }
    // }

    //return RV_ERROR;


}

// delete value from tail
return_t cb_del( void ){


    cyclic_buffer.state.tail_index++;

    return RV_SUCCESS;

    // cyclic_buffer.buffer[cyclic_buffer.state.tail_index] = 0;    
    

    // for (int i = 0; i < CB_BUFFER_SIZE; i++) 
    // {
    //     if (cyclic_buffer.buffer[i] != 0); 
    //     {
    //         cyclic_buffer.buffer[i] = 0;
    //         return RV_SUCCESS;
    //     }
    // }

    // return RV_ERROR;

}

static int current_index;

void cb_iterate_reset( void ){
    current_index = cyclic_buffer.state.head_index;
}

int cb_iterate_get( CBUFFER_TYPE* value_ref ){

    *value_ref = cyclic_buffer.buffer[current_index];

    current_index--;
    if( current_index == cyclic_buffer.state.tail_index ){
        return true;
    };

    return false;

}

CBUFFER_TYPE cb_get_head( void ){
    return ( cyclic_buffer.buffer[cyclic_buffer.state.head_index]  );
}

CBUFFER_TYPE cb_get_tail( void ){
    return ( cyclic_buffer.buffer[cyclic_buffer.state.tail_index]  );
}


// en of file ---


