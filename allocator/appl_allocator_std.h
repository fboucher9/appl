/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_ALLOCATOR_STD_H

/* Reverse include guard */
enum guard_appl_allocator_std_h
{
    inc_appl_allocator_std_h = 1
        /* Header file dependencies */
        + inc_appl_allocator_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_allocator_std : public appl_allocator
{
    public:

        appl_allocator_std();

        virtual
        ~appl_allocator_std();

    protected:

    private:

        appl_allocator_std(
            class appl_allocator_std const & r);

        class appl_allocator_std &
            operator =(
                class appl_allocator_std const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_alloc(
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_buf);

        virtual
        enum appl_status
            v_free(
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

}; // class appl_allocator_std

/* end-of-file: appl_allocator_std.h */