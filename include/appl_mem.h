/* See LICENSE for license details */

/*

*/

#include <misc/appl_extern_c_begin.h>

unsigned long int
    appl_mem_zero(
        void * const
            p_buf,
        unsigned long int const
            i_buf_len);

unsigned long int
    appl_mem_fill(
        void * const
            p_buf,
        unsigned char const
            i_value,
        unsigned long int const
            i_buf_len);

unsigned long int
    appl_mem_copy(
        void * const
            p_dst,
        unsigned long int const
            i_dst_len,
        void const * const
            p_src,
        unsigned long int const
            i_src_len);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_mem.h */
