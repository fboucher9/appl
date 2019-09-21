/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_descriptor_impl_h
{
    inc_appl_thread_descriptor_impl_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_thread_descriptor : public appl_object
{
    public:

        appl_thread_descriptor(
            struct appl_context * const
                p_context);

        virtual
        ~appl_thread_descriptor();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        void
            f_set_callback(
                struct appl_thread_callback const * const
                    p_thread_callback);

        void
            f_set_name(
                struct appl_buf const * const
                    p_name);

        void
            f_copy(
                struct appl_thread_descriptor const * const
                    p_src_descriptor);

        void
            f_dispatch(void);

        bool
            f_get_callback(
                struct appl_thread_callback * const
                    p_thread_callback) const;

        bool
            f_get_name(
                struct appl_buf * const
                    p_name) const;

    protected:

    private:

        // --

        char
            b_callback;

        char
            b_name;

        unsigned char
            uc_reserved[6u];

        // --

        struct appl_thread_callback
            o_callback;

        // --

        struct appl_buf
            o_name;

        // --

        appl_thread_descriptor(
            struct appl_thread_descriptor const & r);

        struct appl_thread_descriptor &
            operator =(
                struct appl_thread_descriptor const & r);

}; // struct appl_thread_descriptor

/* end-of-file: appl_thread_descriptor_impl.h */
