/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_std_node_h
{
    inc_appl_mutex_std_node_h =
        /* Header file dependency */
        inc_appl_mutex_node_h
};

struct appl_mutex_descriptor;

struct appl_context;

struct appl_event;

struct appl_mutex;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_std_node;

class appl_mutex_std_node;

//
//
//
class appl_mutex_std_node : public appl_mutex
{
    friend class appl_event_std_node;

    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

        appl_mutex_std_node();

        virtual
        ~appl_mutex_std_node();

        enum appl_status
            f_init(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor);

    protected:

    private:

        class appl_mutex_impl
            m_mutex_impl;

        bool
            m_mutex_impl_initialized;

        unsigned char
            m_uc_padding[7u];

        appl_mutex_std_node(
            class appl_mutex_std_node const & r);

        class appl_mutex_std_node &
            operator =(
                class appl_mutex_std_node const & r);

        static
        class appl_mutex_std_node *
        convert_handle(
            struct appl_mutex * const
                p_mutex);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

}; // class appl_mutex_std_node

/* end-of-file: appl_mutex_std_node.h */
