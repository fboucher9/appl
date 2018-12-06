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

#include <context/appl_context.h>

#include <appl_unused.h>

#include <thread/appl_thread_node.h>

#include <thread/appl_thread_mgr.h>

#include <appl_mutex_handle.h>

#include <mutex/appl_mutex_node.h>

#include <mutex/appl_mutex_mgr.h>

#include <appl_thread_descriptor.h>

#include <allocator/appl_allocator.h>

#include <appl_allocator_handle.h>

#include <queue/appl_queue.h>

#include <appl_queue_handle.h>

#include <appl_list.h>

#include <appl_clock_handle.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

#include <appl_buf.h>

struct appl_thread_property;

class appl_thread_cache_mgr;

class appl_thread_cache_node;

/*

*/
struct appl_thread_cache_descriptor
{
    struct appl_context *
        p_context;

    class appl_thread_cache_mgr *
        p_thread_cache_mgr;

    struct appl_thread_property const *
        p_thread_property;

}; /* struct appl_thread_cache_descriptor */

/*

*/
struct appl_thread_cache_task
{
    struct appl_list
        o_list;

    /* -- */

    struct appl_thread_descriptor
        o_thread_descriptor;

    /* -- */

    bool
        b_kill;

#define PADDING (1)
#include <appl_padding.h>

}; /* struct appl_thread_cache_task */

union appl_thread_cache_ptr
{
    void *
        p_thread_context;

    struct appl_thread_cache *
        p_thread_cache;

}; /* union appl_thread_cache_ptr */

union appl_thread_cache_task_ptr
{
    struct appl_list *
        p_list;

    struct appl_thread_cache_task *
        p_thread_cache_task;

}; /* union appl_thread_cache_task_ptr */

union appl_thread_cache_node_ptr
{
    class appl_node *
        p_node;

    class appl_thread_cache_node *
        p_thread_cache_node;

}; /* union appl_thread_cache_node_ptr */

//
//
//
struct appl_thread_cache : public appl_thread
{
    public:

        //
        //
        //
        appl_thread_cache() :
            appl_thread(),
            m_thread_cache_mgr(),
            m_thread_cache_node(),
            m_thread_handle(),
            m_queue_used(),
            m_queue_free(),
            m_task()
        {
        }

        //
        //
        //
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
                    p_thread_cache_descriptor)
        {
            enum appl_status
                e_status;

            set_context(
                p_thread_cache_descriptor->p_context);

            m_thread_cache_mgr =
                p_thread_cache_descriptor->p_thread_cache_mgr;

            m_thread_cache_node =
                p_thread_cache_node;

            union appl_thread_cache_ptr
                o_thread_cache_ptr;

            o_thread_cache_ptr.p_thread_cache =
                this;

            struct appl_thread_descriptor
                o_thread_descriptor;

            union appl_buf_ptr
                o_thread_descriptor_ptr;

            o_thread_descriptor_ptr.p_void =
                &(
                    o_thread_descriptor);

            appl_buf_fill(
                o_thread_descriptor_ptr.p_uchar,
                o_thread_descriptor_ptr.p_uchar + sizeof(o_thread_descriptor),
                0);

            o_thread_descriptor.b_callback =
                1;

            o_thread_descriptor.o_callback.p_entry =
                &(
                    appl_thread_cache::s_task);

            o_thread_descriptor.o_callback.p_context =
                o_thread_cache_ptr.p_thread_context;

            e_status =
                m_context->m_thread_mgr->v_create_node(
                    p_thread_cache_descriptor->p_thread_property,
                    &(
                        o_thread_descriptor),
                    &(
                        m_thread_handle));

            if (
                appl_status_ok
                == e_status)
            {
                struct appl_queue_descriptor
                    o_queue_descriptor;

                o_queue_descriptor.i_max_count =
                    1ul;

                e_status =
                    appl_queue_create(
                        m_context,
                        &(
                            o_queue_descriptor),
                        &(
                            m_queue_used));

                if (
                    appl_status_ok
                    == e_status)
                {
                    o_queue_descriptor.i_max_count =
                        1ul;

                    e_status =
                        appl_queue_create(
                            m_context,
                            &(
                                o_queue_descriptor),
                            &(
                                m_queue_free));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        appl_list_init(
                            &(
                                m_task.o_list));

                        m_queue_free->v_push(
                            &(
                                m_task.o_list),
                            1000ul,
                            0);

                        if (
                            appl_status_ok
                            != e_status)
                        {
                            appl_queue_destroy(
                                m_queue_free);
                        }
                    }

                    if (
                        appl_status_ok
                        != e_status)
                    {
                        appl_queue_destroy(
                            m_queue_used);
                    }
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    m_context->m_thread_mgr->v_destroy_node(
                        m_thread_handle);
                }
            }

            return
                e_status;

        } // f_init()

        enum appl_status
            f_deinit(void);

        //
        //
        //
        enum appl_status
            f_kill(void)
        {
            enum appl_status
                e_status;

            union appl_thread_cache_task_ptr
                o_thread_cache_task_ptr;

            e_status =
                m_queue_free->v_pop(
                    &(
                        o_thread_cache_task_ptr.p_list),
                    1000ul,
                    100ul);

            if (
                appl_status_ok
                == e_status)
            {
                o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor.b_callback =
                    0;

                o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor.o_callback.p_entry =
                    0;

                o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor.o_callback.p_context =
                    0;

                o_thread_cache_task_ptr.p_thread_cache_task->b_kill =
                    true;

                e_status =
                    m_queue_used->v_push(
                        o_thread_cache_task_ptr.p_list,
                        1000ul,
                        0ul);
            }

            return
                e_status;

        } // f_kill()

        //
        //
        //
        enum appl_status
            f_start(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor)
        {
            enum appl_status
                e_status;

            union appl_thread_cache_task_ptr
                o_thread_cache_task_ptr;

            e_status =
                m_queue_free->v_pop(
                    &(
                        o_thread_cache_task_ptr.p_list),
                    1000ul,
                    100ul);

            if (
                appl_status_ok
                == e_status)
            {
                o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor =
                    *(
                        p_thread_descriptor);

                o_thread_cache_task_ptr.p_thread_cache_task->b_kill =
                    false;

                e_status =
                    m_queue_used->v_push(
                        o_thread_cache_task_ptr.p_list,
                        1000ul,
                        0ul);
            }

            return
                e_status;

        } // f_start()

        //
        //
        //
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

        // --

        struct appl_thread *
            m_thread_handle;

        struct appl_queue *
            m_queue_used;

        // --

        struct appl_queue *
            m_queue_free;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

        // --

        struct appl_thread_cache_task
            m_task;

        // --

        void
            f_task(void);

        //
        //
        //
        static
        void
            s_task(
                void * const
                    p_thread_context)
        {
            union appl_thread_cache_ptr
                o_thread_cache_ptr;

            o_thread_cache_ptr.p_thread_context =
                p_thread_context;

            struct appl_thread_cache * const
                p_thread_cache =
                o_thread_cache_ptr.p_thread_cache;

            p_thread_cache->f_task();

        } // s_task()

        appl_thread_cache(
            struct appl_thread_cache const & r);

        struct appl_thread_cache &
            operator =(
                struct appl_thread_cache const & r);

        virtual
        appl_size_t
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
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_cache_mgr * const
                    p_thread_cache_mgr,
                struct appl_thread_property const * const
                    p_thread_property,
                class appl_thread_cache_node * * const
                    r_instance)
        {
            enum appl_status
                e_status;

            struct appl_thread_cache_descriptor
                o_thread_cache_descriptor;

            o_thread_cache_descriptor.p_context =
                p_allocator->get_context();

            o_thread_cache_descriptor.p_thread_cache_mgr =
                p_thread_cache_mgr;

            o_thread_cache_descriptor.p_thread_property =
                p_thread_property;

            e_status =
                appl_new(
                    p_allocator,
                    &(
                        o_thread_cache_descriptor),
                    r_instance);

            return
                e_status;

        } // s_create_instance()

        //
        //
        //
        static
        enum appl_status
            s_destroy_instance(
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_cache_node * const
                    p_thread_cache_node)
        {
            return
                appl_delete(
                    p_allocator,
                    p_thread_cache_node);

        } // s_destroy_instance()

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
        ~appl_thread_cache_node();

        //
        //
        //
        enum appl_status
            f_init(
                struct appl_thread_cache_descriptor const * const
                    p_thread_cache_descriptor)
        {
            enum appl_status
                e_status;

            e_status =
                m_thread_cache.f_init(
                    this,
                    p_thread_cache_descriptor);

            if (
                appl_status_ok
                == e_status)
            {
            }

            return
                e_status;

        } // init()

        //
        //
        //
        enum appl_status
            f_start(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor)
        {
            enum appl_status
                e_status;

            e_status =
                m_thread_cache.f_start(
                    p_thread_descriptor);

            return
                e_status;

        } // f_start()

        //
        //
        //
        enum appl_status
            f_kill(void)
        {
            enum appl_status
                e_status;

            m_thread_cache.f_kill();

            e_status =
                appl_status_ok;

            return
                e_status;

        } // f_kill()

    protected:

    private:

        struct appl_thread_cache
            m_thread_cache;

        appl_thread_cache_node(
            class appl_thread_cache_node const & r);

        class appl_thread_cache_node &
            operator =(
                class appl_thread_cache_node const & r);

        virtual
        appl_size_t
            v_cleanup(void)
        {
            m_thread_cache.f_deinit();

            return
                sizeof(class appl_thread_cache_node);

        } // v_cleanup()

}; // class appl_thread_cache_node

appl_thread_cache_node::~appl_thread_cache_node()
{
}

//
//
//
class appl_thread_cache_mgr : public appl_object
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_cache_mgr * * const
                    r_instance)
        {
            enum appl_status
                e_status;

            e_status =
                appl_new(
                    p_allocator,
                    r_instance);

            return
                e_status;

        }

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_cache_mgr * const
                    p_instance)
        {
            return
                appl_delete(
                    p_allocator,
                    p_instance);
        }

        enum appl_status
            f_create_node(
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                struct appl_thread_cache * * const
                    r_thread_cache)
        {
            enum appl_status
                e_status;

            union appl_thread_cache_node_ptr
                o_thread_cache_node_ptr;

            appl_mutex_lock(m_lock);

            if (m_unused_nodes.p_next != &m_unused_nodes)
            {
                o_thread_cache_node_ptr.p_node =
                    m_unused_nodes.p_next;

                appl_node::join(
                    o_thread_cache_node_ptr.p_thread_cache_node,
                    o_thread_cache_node_ptr.p_thread_cache_node);

                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_thread_cache_node::s_create_instance(
                        m_context->m_allocator,
                        this,
                        p_thread_property,
                        &(
                            o_thread_cache_node_ptr.p_thread_cache_node));
            }

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_thread_cache) =
                    o_thread_cache_node_ptr.p_thread_cache_node->f_get();

                e_status =
                    o_thread_cache_node_ptr.p_thread_cache_node->f_start(
                        p_thread_descriptor);

                if (
                    appl_status_ok
                    == e_status)
                {
                    appl_node::join(
                        o_thread_cache_node_ptr.p_thread_cache_node,
                        &(
                            m_active_nodes));
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    appl_node::join(
                        o_thread_cache_node_ptr.p_thread_cache_node,
                        &(
                            m_unused_nodes));
                }
            }

            appl_mutex_unlock(m_lock);

            return
                e_status;

        } // f_create_node()

        //
        //
        //
        enum appl_status
            f_destroy_node(
                struct appl_thread_cache * const
                    p_thread_cache)
        {
            // Object will be retired to unused list
            return
                appl_delete(
                    0,
                    p_thread_cache);

        } // f_destroy_node()

        //
        //
        //
        void
            f_retire(
                class appl_thread_cache_node * const
                    p_thread_cache_node)
        {
            appl_mutex_lock(m_lock);

            appl_node::join(
                p_thread_cache_node,
                p_thread_cache_node);

            appl_node::join(
                p_thread_cache_node,
                &(
                    m_unused_nodes));

            appl_mutex_unlock(m_lock);

        } // f_retire()

        //
        //
        //
        void
            f_destroy_node(
                class appl_thread_cache_node * const
                    p_thread_cache_node)
        {
            appl_mutex_lock(m_lock);

            appl_thread_cache_node::s_destroy_instance(
                m_context->m_allocator,
                p_thread_cache_node);

            appl_mutex_unlock(m_lock);

        } // f_destroy_node()

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
        ~appl_thread_cache_mgr();

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

    protected:

    private:

        struct appl_mutex *
            m_lock;

        class appl_node
            m_unused_nodes;

        class appl_node
            m_active_nodes;

        appl_thread_cache_mgr(
            class appl_thread_cache_mgr const & r);

        class appl_thread_cache_mgr &
            operator =(
                class appl_thread_cache_mgr const & r);

        //
        //
        //
        virtual
        appl_size_t
            v_cleanup(void)
        {
            // Wait for all active threads to complete...
            {
                bool
                    b_continue;

                b_continue =
                    true;

                while (
                    b_continue)
                {
                    appl_mutex_lock(m_lock);

                    if (
                        m_active_nodes.p_next
                        != &(
                            m_active_nodes))
                    {
                        // Kill this thread
                    }
                    else
                    {
                        b_continue =
                            false;
                    }

                    appl_mutex_unlock(m_lock);

                    if (
                        b_continue)
                    {
#if defined APPL_DEBUG
                        {
                            static unsigned char const s_msg[] =
                                "appl_thread_cache_mgr::v_cleanup wait for active nodes\n";

                            appl_debug_print0(
                                m_context,
                                s_msg);
                        }
#endif /* #if defined APPL_DEBUG */

                        appl_clock_delay(
                            m_context,
                            1000ul,
                            100ul);
                    }
                }
            }

            // Destroy all unused threads...
            {
                bool
                    b_continue;

                b_continue =
                    true;

                while (
                    b_continue)
                {
                    // Find an unused thread

                    appl_mutex_lock(m_lock);

                    if (
                        m_unused_nodes.p_next
                        != &(
                            m_unused_nodes))
                    {
                        // Kill this thread
                        union appl_thread_cache_node_ptr
                            o_thread_cache_node_ptr;

                        o_thread_cache_node_ptr.p_node =
                            m_unused_nodes.p_next;

                        o_thread_cache_node_ptr.p_thread_cache_node->f_kill();
                    }
                    else
                    {
                        b_continue =
                            false;
                    }

                    appl_mutex_unlock(m_lock);

                    if (
                        b_continue)
                    {
#if defined APPL_DEBUG
                        {
                            static unsigned char const s_msg[] =
                                "appl_thread_cache_mgr::v_cleanup wait for unused nodes\n";

                            appl_debug_print0(
                                m_context,
                                s_msg);
                        }
#endif /* #if defined APPL_DEBUG */

                        appl_clock_delay(
                            m_context,
                            1000ul,
                            100ul);
                    }
                }
            }

            appl_mutex_destroy(
                m_lock);

            return
                sizeof(class appl_thread_cache_mgr);

        } // v_cleanup()

}; // class appl_thread_cache_mgr

appl_thread_cache_mgr::~appl_thread_cache_mgr()
{
}

//
//
//
appl_size_t
    appl_thread_cache::v_cleanup(void)
{
    // Keep this object intact!

    // Notify cache node of destruction
    if (
        m_thread_cache_mgr)
    {
        m_thread_cache_mgr->f_retire(
            m_thread_cache_node);
    }

    // We have handled the destruction
    return
        0;

} // v_cleanup()

//
//
//
void
    appl_thread_cache::f_task(void)
{
    bool
        b_continue;

    b_continue =
        true;

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "appl_thread_cache::f_task enter {...\n";

        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    while (
        b_continue)
    {
        // Pop a task from queue else wait to be killed
        union appl_thread_cache_task_ptr
            o_thread_cache_task_ptr;

        enum appl_status
            e_status;

        e_status =
            m_queue_used->v_pop(
                &(
                    o_thread_cache_task_ptr.p_list),
                1000ul,
                100ul);

        if (
            appl_status_ok
            == e_status)
        {
            // Check for quit message ...
            if (o_thread_cache_task_ptr.p_thread_cache_task->b_kill)
            {
#if defined APPL_DEBUG
                {
                    static unsigned char const s_msg[] =
                        "appl_thread_cache::f_task kill detected\n";

                    appl_debug_print0(
                        m_context,
                        s_msg);
                }
#endif /* #if defined APPL_DEBUG */

                b_continue =
                    false;
            }
            else
            {
#if defined APPL_DEBUG
                {
                    static unsigned char const s_msg[] =
                        "appl_thread_cache::f_task before cb\n";

                    appl_debug_print0(
                        m_context,
                        s_msg);
                }
#endif /* #if defined APPL_DEBUG */

                (*(o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor.o_callback.p_entry))(
                    o_thread_cache_task_ptr.p_thread_cache_task->o_thread_descriptor.o_callback.p_context);

#if defined APPL_DEBUG
                {
                    static unsigned char const s_msg[] =
                        "appl_thread_cache::f_task after cb\n";

                    appl_debug_print0(
                        m_context,
                        s_msg);
                }
#endif /* #if defined APPL_DEBUG */
            }

            // Free the node
            m_queue_free->v_push(
                o_thread_cache_task_ptr.p_list,
                1000ul,
                0ul);

            // Retire the node ?
        }
    }

    // Destroy ourselves
    m_thread_cache_mgr->f_destroy_node(
        m_thread_cache_node);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "appl_thread_cache::f_task leave ...}\n";

        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

} // f_task()

//
//
//
enum appl_status
appl_thread_cache::f_deinit(void)
{
    enum appl_status
        e_status;

    appl_queue_destroy(
        m_queue_free);

    appl_queue_destroy(
        m_queue_used);

    m_context->m_thread_mgr->v_destroy_node(
        m_thread_handle);

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_deinit()

//
//
//
class appl_thread_cache_service
{
    public:

        //
        //
        //
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                struct appl_thread_cache * * const
                    r_thread_cache)
        {
            enum appl_status
                e_status;

            class appl_thread_cache_mgr *
                p_thread_cache_mgr;

            e_status =
                p_context->v_thread_cache_mgr(
                    &(
                        p_thread_cache_mgr));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    p_thread_cache_mgr->f_create_node(
                        p_thread_property,
                        p_thread_descriptor,
                        r_thread_cache);
            }

            return
                e_status;

        } // s_create()

        //
        //
        //
        static
        enum appl_status
            s_destroy(
                struct appl_thread_cache * const
                    p_thread_cache)
        {
            enum appl_status
                e_status;

            struct appl_context * const
                p_context =
                p_thread_cache->get_context();

            class appl_thread_cache_mgr *
                p_thread_cache_mgr;

            e_status =
                p_context->v_thread_cache_mgr(
                    &(
                        p_thread_cache_mgr));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    p_thread_cache_mgr->f_destroy_node(
                        p_thread_cache);
            }

            return
                e_status;

        } // s_destroy()

        //
        //
        //
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
            p_thread_property,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread_cache * * const
            r_thread_cache)
{
    return
        appl_thread_cache_service::s_create(
            p_context,
            p_thread_property,
            p_thread_descriptor,
            r_thread_cache);

} /* create() */

/*

*/
enum appl_status
    appl_thread_cache_destroy(
        struct appl_thread_cache * const
            p_thread_cache)
{
    return
        appl_thread_cache_service::s_destroy(
            p_thread_cache);

} /* destroy() */

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

extern
enum appl_status
appl_thread_cache_mgr_create(
    struct appl_allocator * const
        p_allocator,
    class appl_thread_cache_mgr * * const
        r_instance);

extern
enum appl_status
appl_thread_cache_mgr_destroy(
    struct appl_allocator * const
        p_allocator,
    class appl_thread_cache_mgr * const
        p_thread_cache_mgr);

//
//
//
enum appl_status
appl_thread_cache_mgr_create(
    struct appl_allocator * const
        p_allocator,
    class appl_thread_cache_mgr * * const
        r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_cache_mgr::s_create(
            p_allocator,
            r_instance);

    return
        e_status;

} // appl_thread_cache_mgr_create()

//
//
//
enum appl_status
appl_thread_cache_mgr_destroy(
    struct appl_allocator * const
        p_allocator,
    class appl_thread_cache_mgr * const
        p_thread_cache_mgr)
{
    return
        appl_thread_cache_mgr::s_destroy(
            p_allocator,
            p_thread_cache_mgr);

} // appl_thread_cache_mgr_destroy()

/* end-of-file: appl_thread_cache.cpp */
