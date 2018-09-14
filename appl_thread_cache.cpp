/* See LICENSE for license details */

/*

Comments:

    Create a thread node
    Support of start and stop
    When object is destroyed, return it to unused node list

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_cache.h>

#include <appl_node.h>

#include <appl_context.h>

#include <appl_unused.h>

#include <appl_object_handle.h>

#include <appl_thread_handle.h>

#include <appl_thread_node.h>

#include <appl_mutex_handle.h>

#include <appl_event_handle.h>

#include <appl_thread_descriptor.h>

struct appl_thread_property;

class appl_thread_cache_mgr;

class appl_thread_cache_node;

struct appl_thread_cache_descriptor
{
    class appl_thread_cache_mgr *
        p_thread_cache_mgr;

    struct appl_thread_property const *
        p_property;

}; /* struct appl_thread_cache_descriptor */

union appl_thread_cache_task_ptr
{
    void *
        p_thread_context;

    struct appl_thread_cache *
        p_thread_cache;

}; /* union appl_thread_cache_task_ptr */

//
//
//
struct appl_thread_cache : public appl_thread
{
    public:

        appl_thread_cache() :
            appl_thread(),
            m_thread_cache_mgr(),
            m_thread_cache_node(),
            m_thread_handle(),
            m_lock(),
            m_event(),
            m_descriptor()
        {
        }

        virtual
        ~appl_thread_cache()
        {
        }

        //
        //
        //
        enum appl_status
            f_init(
                class appl_thread_cache_node * const
                    p_thread_cache_node,
                struct appl_thread_cache_descriptor const * const
                    p_descriptor)
        {
            enum appl_status
                e_status;

            m_thread_cache_mgr =
                p_descriptor->p_thread_cache_mgr;

            m_thread_cache_node =
                p_thread_cache_node;

            e_status =
                appl_thread_create(
                    this,
                    p_descriptor->p_property,
                    &(
                        m_thread_handle));

            if (
                appl_status_ok
                == e_status)
            {
                union appl_thread_cache_task_ptr
                    o_task_ptr;

                o_task_ptr.p_thread_cache =
                    this;

                e_status =
                    m_thread_handle->v_start(
                        &(
                            appl_thread_cache::s_task),
                        o_task_ptr.p_thread_context);

                if (
                    appl_status_ok
                    == e_status)
                {
                }
            }

            return
                e_status;

        } // f_init()

        virtual
        enum appl_status
            v_start(
                void (* const p_callback)(
                    void * const p_context),
                void * const
                    p_context)
        {
            return
                m_thread_handle->v_start(
                    p_callback,
                    p_context);

        } // v_start()

        virtual
        enum appl_status
            v_detach(void)
        {
            enum appl_status
                e_status;

            // detach does not work, because we lose the thread handle!

            // we would need to hook the automatic destroy...

            e_status =
                appl_status_fail;

            return
                e_status;

        } // v_detach()

        virtual
        enum appl_status
            v_stop(
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count)
        {
            return
                m_thread_handle->v_stop(
                    i_wait_freq,
                    i_wait_count);

        } // v_stop()

        virtual
        enum appl_status
            v_interrupt(void)
        {
            return
                m_thread_handle->v_interrupt();

        } // v_interrupt()

    private:

        class appl_thread_cache_mgr *
            m_thread_cache_mgr;

        class appl_thread_cache_node *
            m_thread_cache_node;

        struct appl_thread *
            m_thread_handle;

        struct appl_mutex *
            m_lock;

        struct appl_event *
            m_event;

        struct appl_thread_descriptor
            m_descriptor;

        static
        void
            s_new(
                void * const
                    p_placement)
        {
            new (p_placement)
                struct appl_thread_cache;

        } // s_new()

        //
        //
        //
        void
            f_task(void)
        {

        } // f_task()

        //
        //
        //
        static
        void
            s_task(
                void * const
                    p_thread_context)
        {
            union appl_thread_cache_task_ptr
                o_task_ptr;

            o_task_ptr.p_thread_context =
                p_thread_context;

            struct appl_thread_cache * const
                p_thread_cache =
                o_task_ptr.p_thread_cache;

            p_thread_cache->f_task();

        } // s_task()

        appl_thread_cache(
            struct appl_thread_cache const & r);

        struct appl_thread_cache &
            operator =(
                struct appl_thread_cache const & r);

        enum appl_status
            v_cleanup(void);


}; // struct appl_thread_cache

//
//
//
class appl_thread_cache_node : public appl_node
{
    public:

        //
        //
        //
        static
        enum appl_status
            s_create_instance(
                struct appl_context * const
                    p_context,
                class appl_thread_cache_mgr * const
                    p_thread_cache_mgr,
                struct appl_thread_property const * const
                    p_property,
                class appl_thread_cache_node * * const
                    r_instance)
        {
            enum appl_status
                e_status;

            struct appl_thread_cache_descriptor
                o_descriptor;

            o_descriptor.p_thread_cache_mgr =
                p_thread_cache_mgr;

            o_descriptor.p_property =
                p_property;

            e_status =
                appl_object::s_create(
                    p_context,
                    (&
                        appl_thread_cache_node::s_new),
                    (&
                         appl_thread_cache_node::f_init),
                    &(
                        o_descriptor),
                    r_instance);

            return
                e_status;

        } // s_create_instance()

        //
        //
        //
        struct appl_thread_cache *
            f_get(void)
        {
            return
                &(
                    m_thread_cache);

        } // f_get()

    protected:

        //
        //
        //
        appl_thread_cache_node() :
            appl_node(),
            m_thread_cache()
        {
        }

        //
        //
        //
        virtual
        ~appl_thread_cache_node()
        {
        }

    private:

        struct appl_thread_cache
            m_thread_cache;

        //
        //
        //
        static
        void
            s_new(
                void * const
                    p_placement)
        {
            new (p_placement)
                class appl_thread_cache_node;

        } // s_new

        //
        //
        //
        enum appl_status
            f_init(
                struct appl_thread_cache_descriptor const * const
                    p_descriptor)
        {
            enum appl_status
                e_status;

            e_status =
                m_thread_cache.f_init(
                    this,
                    p_descriptor);

            return
                e_status;

        } // init()

        appl_thread_cache_node(
            class appl_thread_cache_node const & r);

        class appl_thread_cache_node &
            operator =(
                class appl_thread_cache_node const & r);

}; // class appl_thread_cache_node

//
//
//
class appl_thread_cache_mgr : public appl_object
{
    public:

        static
        enum appl_status
            f_create_instance(
                struct appl_context * const
                    p_context,
                class appl_thread_cache_mgr * * const
                    r_instance)
        {
            enum appl_status
                e_status;

            e_status =
                appl_object::s_create(
                    p_context,
                    (&
                        appl_thread_cache_mgr::s_new),
                    (&
                        appl_thread_cache_mgr::f_init),
                    r_instance);

            return
                e_status;

        }

        enum appl_status
            f_create_node(
                struct appl_thread_property const * const
                    p_property,
                struct appl_thread_cache * * const
                    r_thread_cache)
        {
            enum appl_status
                e_status;

            class appl_thread_cache_node *
                p_thread_cache_node;

            appl_unused(
                p_property);

            appl_mutex_lock(
                m_lock);

            if (m_unused_nodes.p_next != &m_unused_nodes)
            {
                p_thread_cache_node =
                    static_cast<class appl_thread_cache_node *>(
                        m_unused_nodes.p_next);

                appl_node::join(
                    p_thread_cache_node,
                    p_thread_cache_node);

                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_thread_cache_node::s_create_instance(
                        m_context,
                        this,
                        p_property,
                        &(
                            p_thread_cache_node));
            }

            if (
                appl_status_ok
                == e_status)
            {
                appl_node::join(
                    p_thread_cache_node,
                    &(
                        m_active_nodes));

                *(
                    r_thread_cache) =
                    p_thread_cache_node->f_get();
            }

            appl_mutex_unlock(
                m_lock);

            return
                e_status;

        } // f_create_node()

        void
            f_retire(
                class appl_thread_cache_node * const
                    p_thread_cache_node)
        {
            appl_node::join(
                p_thread_cache_node,
                p_thread_cache_node);

            appl_node::join(
                p_thread_cache_node,
                &(
                    m_unused_nodes));

        } // f_retire()

    protected:

        //
        //
        //
        appl_thread_cache_mgr() :
            appl_object(),
            m_lock(),
            m_unused_nodes(),
            m_active_nodes()
        {
        }

        //
        //
        //
        virtual
        ~appl_thread_cache_mgr()
        {
        }

    private:

        struct appl_mutex *
            m_lock;

        class appl_node
            m_unused_nodes;

        class appl_node
            m_active_nodes;

        //
        //
        //
        static
        void
            s_new(
                void * const
                    p_placement)
        {
            new (
                p_placement)
                class appl_thread_cache_mgr;

        } // s_new()

        appl_thread_cache_mgr(
            class appl_thread_cache_mgr const & r);

        class appl_thread_cache_mgr &
            operator =(
                class appl_thread_cache_mgr const & r);

        //
        //
        //
        enum appl_status
            f_init(void)
        {
            enum appl_status
                e_status;

            struct appl_mutex_descriptor
                o_mutex_descriptor;

            appl_mutex_create(
                m_context,
                &(
                    o_mutex_descriptor),
                &(
                    m_lock));

            e_status =
                appl_status_ok;

            return
                e_status;

        }

        //
        //
        //
        virtual
        enum appl_status
            v_cleanup(void)
        {
            appl_object_destroy(
                appl_mutex_parent(
                    m_lock));

            return
                appl_status_ok;

        } // v_cleanup()

}; // class appl_thread_cache_mgr

//
//
//
enum appl_status
    appl_thread_cache::v_cleanup(void)
{
    enum appl_status
        e_status;

    // Keep this object intact!

    // Notify cache node of destruction
    if (
        m_thread_cache_mgr)
    {
        m_thread_cache_mgr->f_retire(
            m_thread_cache_node);
    }

    // We have handled the destruction
    e_status =
        appl_status_fail;

    return
        e_status;

}
//
//
//
class appl_thread_cache_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_thread_property const * const
                    p_property,
                struct appl_thread_cache * * const
                    r_thread_cache)
        {
            class appl_thread_cache_mgr * const
                p_thread_cache_mgr =
                p_context->m_thread_cache_mgr;

            enum appl_status
                e_status =
                p_thread_cache_mgr->f_create_node(
                    p_property,
                    r_thread_cache);

            return
                e_status;

        } // s_create()

        static
        struct appl_thread *
            s_parent(
                struct appl_thread_cache * const
                    p_thread_cache)
        {
            return
                p_thread_cache;

        } // s_parent()

}; // class appl_thread_cache_service

/*

*/
enum appl_status
    appl_thread_cache_create(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_property,
        struct appl_thread_cache * * const
            r_thread_cache)
{
    return
        appl_thread_cache_service::s_create(
            p_context,
            p_property,
            r_thread_cache);

} /* create() */

/*

*/
struct appl_thread *
    appl_thread_cache_parent(
        struct appl_thread_cache * const
            p_thread_cache)
{
    return
        appl_thread_cache_service::s_parent(
            p_thread_cache);

} /* parent() */

/* end-of-file: appl_thread_cache.cpp */
