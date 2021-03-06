/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_std_h
{
    inc_appl_pool_std_h =
        /* Header file dependencies */
        inc_appl_pool_h
        + inc_appl_list_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_pool_std : public appl_pool
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_pool_descriptor const * const
                    p_pool_descriptor,
                class appl_pool_std * * const
                    r_instance);

        appl_pool_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_pool_std();

        enum appl_status
            f_init(
                struct appl_pool_descriptor const * const
                    p_descriptor);

    protected:

    private:

        // list of available items
        struct appl_list
            m_available_items;

        // --

        struct appl_pool_descriptor
            m_descriptor;

        // --

        // size in bytes of each item
        appl_size_t
            m_count_remain;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

        // --

        appl_pool_std(
            class appl_pool_std const & r);

        class appl_pool_std &
            operator =(
                class appl_pool_std const & r);

        virtual
        appl_size_t
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

}; // class appl_pool_std

/* end-of-file: appl_pool_std.h */
