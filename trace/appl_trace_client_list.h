/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_client_list_h
{
    inc_appl_trace_client_list_h = 1
        /* Header file dependencies */
        | inc_appl_object_h
        | inc_appl_node_h
        /* ... */
}; /* enum guard_appl_trace_client_list_h */

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_trace_client_list : public appl_object
{
    public:

        appl_trace_client_list(
            struct appl_context * const
                p_context);

        virtual
        ~appl_trace_client_list();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        enum appl_status
            f_register(
                struct appl_trace_descriptor const * const
                    p_descriptor,
                struct appl_trace_client * * const
                    r_instance);

        enum appl_status
            f_unregister(
                struct appl_trace_client * const
                    p_instance);

    protected:

    private:

        class appl_node
            m_clients;

        appl_trace_client_list(
            class appl_trace_client_list const & r);

        class appl_trace_client_list &
            operator =(
                class appl_trace_client_list const & r);

}; // class appl_trace_client_list

/* end-of-file: appl_trace_client_list.h */
