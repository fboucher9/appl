/* See LICENSE for license details */

#define INC_APPL_CHUNK_H

enum guard_appl_chunk_h
{
    inc_appl_chunk_h = 1
        + inc_appl_object_h
};

//
//  Class: appl_chunk
//
//  Description:
//      Interface for serial buffer of unknown length.
//
struct appl_chunk : public appl_object
{
    public:

        virtual
        enum appl_status
        v_write(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

        virtual
        enum appl_status
        v_length(
            unsigned long int * const
                r_length) const;

        virtual
        enum appl_status
        v_read(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max) const;

        virtual
        enum appl_status
        v_reset(void);

        appl_chunk(
            struct appl_context * const
                p_context);

        virtual
        ~appl_chunk();

    protected:

    private:

        appl_chunk(
            struct appl_chunk const & r);

        struct appl_chunk &
            operator =(
                struct appl_chunk const & r);

}; // struct appl_chunk

/* end-of-file: appl_chunk.h */
