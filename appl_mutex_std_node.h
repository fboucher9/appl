/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_STD_NODE_H
#error include appl_mutex_std_node.h once
#endif /* #if defined INC_APPL_MUTEX_STD_NODE_H */

#define INC_APPL_MUTEX_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_MUTEX_NODE_H
#error include appl_mutex_node.h before
#endif /* #if ! defined INC_APPL_MUTEX_NODE_H */

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
            create_instance(
                struct appl_context * const
                    p_context,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

    protected:

        appl_mutex_std_node();

        virtual
        ~appl_mutex_std_node();

    private:

        pthread_mutex_t
            m_pthread_mutex_storage;

        bool
            m_pthread_mutex_initialized;

        unsigned char
            m_uc_padding[7u];

        appl_mutex_std_node(
            class appl_mutex_std_node const & r);

        class appl_mutex_std_node &
            operator =(
                class appl_mutex_std_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        enum appl_status
            init(void);

        virtual
        enum appl_status
            cleanup(void);

        virtual
        enum appl_status
            v_lock(void);

        virtual
        enum appl_status
            v_unlock(void);

}; // class appl_mutex_std_node

/* end-of-file: appl_mutex_std_node.h */
