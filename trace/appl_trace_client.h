/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_client_h
{
    inc_appl_trace_client_h = 1
        /* Header file dependencies */
        | inc_appl_node_h
        | inc_appl_trace_handle_h
        /* ... */
}; /* enum guard_appl_trace_client_h */

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_trace_client : public appl_node
{
    public:

        appl_trace_client(
            struct appl_context * const
                p_context);

        virtual
        ~appl_trace_client();

        enum appl_status
            f_init(
                struct appl_trace_descriptor const * const
                    p_trace_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        enum appl_status
            f_notify(
                struct appl_trace_message const * const
                    p_trace_message);

    protected:

    private:

        struct appl_trace_descriptor
            m_descriptor;

        appl_trace_client(
            struct appl_trace_client const & r);

        struct appl_trace_client &
            operator =(
                struct appl_trace_client const & r);

}; // struct appl_trace_client

/* end-of-file: appl_trace_client.h */
