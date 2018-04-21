/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <dlfcn.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

#include <appl_status.h>

#include <appl_library_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_unused.h>

#include <appl_heap.h>

#include <appl_buf.h>

#include <appl_convert.h>

//
//
//
struct appl_library : public appl_object
{
    public:

        //
        //
        //
        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const
        {
            appl_unused(
                p_symbol_name_min,
                p_symbol_name_max,
                r_symbol);
            return
                appl_status_not_implemented;
        }

    protected:

        //
        //
        //
        appl_library() :
            appl_object()
        {
        }

        //
        //
        //
        virtual
        ~appl_library()
        {
        }

    private:

        appl_library(
            struct appl_library const & r);

        struct appl_library &
            operator =(
                struct appl_library const & r);

}; // struct appl_library

#if defined APPL_OS_LINUX

//
//
//
class appl_library_std_node : public appl_library
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
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            return
                appl_object::s_create(
                    p_context,
                    sizeof(
                        class appl_library_std_node),
                    (&
                        appl_library_std_node::s_new),
                    (&
                        appl_library_std_node::init),
                    p_library_descriptor,
                    r_library);

        } // s_create()

    protected:

        //
        //
        //
        appl_library_std_node() :
            appl_library()
        {
        }

        //
        //
        //
        virtual
        ~appl_library_std_node()
        {
        }

        //
        //
        //
        enum appl_status
            init(
                struct appl_library_descriptor const * const
                    p_library_descriptor)
        {
            appl_unused(
                p_library_descriptor);

            return
                appl_status_ok;

        } // init()

    private:

        appl_library_std_node(
            class appl_library_std_node const & r);

        class appl_library_std_node &
            operator =(
                class appl_library_std_node const & r);

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
                class appl_library_std_node;

        } // s_new()

}; // class appl_library_std_node

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

//
//
//
class appl_library_w32_node : public appl_library
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
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            return
                appl_object::s_create(
                    p_context,
                    sizeof(
                        class appl_library_w32_node),
                    (&
                        appl_library_w32_node::s_new),
                    (&
                        appl_library_w32_node::init),
                    p_library_descriptor,
                    r_library);

        } // s_create()

    protected:

        //
        //
        //
        appl_library_w32_node() :
            appl_library(),
            m_library_handle()
        {
        }

        //
        //
        //
        virtual
        ~appl_library_w32_node()
        {
        }

        //
        //
        //
        enum appl_status
            init(
                struct appl_library_descriptor const * const
                    p_library_descriptor)
        {
            enum appl_status
                e_status;

            class appl_heap * const
                p_heap =
                m_context->m_heap;

            unsigned long int const
                i_name_len =
                appl_buf_len(
                    p_library_descriptor->p_name_min,
                    p_library_descriptor->p_name_max);

            unsigned char *
                p_name0;

            e_status =
                p_heap->alloc_object_array(
                    i_name_len,
                    &(
                        p_name0));

            if (
                appl_status_ok
                == e_status)
            {
                appl_buf_copy(
                    p_name0,
                    p_name0 + i_name_len,
                    p_library_descriptor->p_name_min,
                    p_library_descriptor->p_name_max);

                p_name0[i_name_len] =
                    0;

                m_library_handle =
                    LoadLibraryA(
                        appl_convert(
                            p_name0));

                if (
                    m_library_handle)
                {
                }
                else
                {
                    e_status =
                        appl_status_fail;
                }

                p_heap->v_free(
                    p_name0);
            }

            return
                e_status;

        } // init()

    private:

        HMODULE
            m_library_handle;

        appl_library_w32_node(
            class appl_library_w32_node const & r);

        class appl_library_w32_node &
            operator =(
                class appl_library_w32_node const & r);

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
                class appl_library_w32_node;

        } // s_new()

}; // class appl_library_w32_node

#endif /* #if defined APPL_OS_WINDOWS */

//
//
//
class appl_library_mgr : public appl_object
{
    public:

        //
        //
        //
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            appl_unused(
                p_library_descriptor,
                r_library);
            return
                appl_status_not_implemented;
        } // v_create_node()

    protected:

        //
        //
        //
        appl_library_mgr() :
            appl_object()
        {
        }

        //
        //
        //
        virtual
        ~appl_library_mgr()
        {
        }

    private:

        appl_library_mgr(
            class appl_library_mgr const & r);

        class appl_library_mgr &
            operator =(
                class appl_library_mgr const & r);

}; // class appl_library_mgr

#if defined APPL_OS_LINUX

//
//
//
class appl_library_std_mgr : public appl_library_mgr
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
                struct appl_library_mgr * * const
                    r_library_mgr)
        {
            return
                appl_object::s_create(
                    p_context,
                    sizeof(
                        class appl_library_std_mgr),
                    (&
                        appl_library_std_mgr::s_new),
                    (&
                        appl_library_std_mgr::init_dummy),
                    r_library_mgr);

        } // s_create()

    protected:

        //
        //
        //
        appl_library_std_mgr() :
            appl_library_mgr()
        {
        }

        //
        //
        //
        virtual
        ~appl_library_std_mgr()
        {
        }

    private:

        appl_library_std_mgr(
            class appl_library_std_mgr const & r);

        class appl_library_std_mgr &
            operator =(
                class appl_library_std_mgr const & r);

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
                class appl_library_std_mgr;

        } // s_new()

        //
        //
        //
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            appl_unused(
                p_library_descriptor,
                r_library);

            return
                appl_status_not_implemented;

        } // v_create_node()

}; // class appl_library_std_mgr

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

//
//
//
class appl_library_w32_mgr : public appl_library_mgr
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
                struct appl_library_mgr * * const
                    r_library_mgr)
        {
            return
                appl_object::s_create(
                    p_context,
                    sizeof(
                        class appl_library_w32_mgr),
                    (&
                        appl_library_w32_mgr::s_new),
                    (&
                        appl_library_w32_mgr::init_dummy),
                    r_library_mgr);

        } // s_create()

    protected:

        //
        //
        //
        appl_library_w32_mgr() :
            appl_library_mgr()
        {
        }

        //
        //
        //
        virtual
        ~appl_library_w32_mgr()
        {
        }

    private:

        appl_library_w32_mgr(
            class appl_library_w32_mgr const & r);

        class appl_library_w32_mgr &
            operator =(
                class appl_library_w32_mgr const & r);

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
                class appl_library_w32_mgr;

        } // s_new()

        //
        //
        //
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            return
                appl_library_w32_node::s_create(
                    m_context,
                    p_library_descriptor,
                    r_library);

        } // v_create_node()

}; // class appl_library_w32_mgr

#endif /* #if defined APPL_OS_WINDOWS */

extern
enum appl_status
    appl_library_mgr_create(
        struct appl_context * const
            p_context,
        class appl_library_mgr * * const
            r_library_mgr);

extern
enum appl_status
    appl_library_mgr_destroy(
        class appl_library_mgr * const
            p_library_mgr);

//
//
//
enum appl_status
    appl_library_mgr_create(
        struct appl_context * const
            p_context,
        class appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    e_status =
        appl_library_std_mgr::s_create(
            p_context,
            r_library_mgr);

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_library_w32_mgr::s_create(
            p_context,
            r_library_mgr);

#else /* #if definde APPL_OS_Xx */

    e_status =
        appl_status_not_implemented;

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // appl_library_mgr_create()

//
//
//
enum appl_status
    appl_library_mgr_destroy(
        class appl_library_mgr * const
            p_library_mgr)
{
    return
        p_library_mgr->destroy();

} // appl_library_mgr_destroy()

//
//
//
class appl_library_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
            return
                p_context->m_library_mgr->v_create_node(
                    p_library_descriptor,
                    r_library);

        } // s_create()

        static
        enum appl_status
            s_query(
                struct appl_library const * const
                    p_library,
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol)
        {
            return
                p_library->v_query(
                    p_symbol_name_min,
                    p_symbol_name_max,
                    r_symbol);

        } // s_query()

}; // class appl_library_service

/*

*/
enum appl_status
appl_library_create(
    struct appl_context * const
        p_context,
    struct appl_library_descriptor const * const
        p_library_descriptor,
    struct appl_library * * const
        r_library)
{
    return
        appl_library_service::s_create(
            p_context,
            p_library_descriptor,
            r_library);

} /* create() */

/*

*/
enum appl_status
appl_library_destroy(
    struct appl_library * const
        p_library)
{
    return
        p_library->destroy();

} /* destroy() */

/*

*/
struct appl_object *
appl_library_parent(
    struct appl_library * const
        p_library)
{
    return
        p_library;

} /* parent() */

/*

*/
struct appl_object const *
appl_library_const_parent(
    struct appl_library const * const
        p_library)
{
    return
        p_library;

} /* const_parent() */

/*

*/
enum appl_status
appl_library_query(
    struct appl_library const * const
        p_library,
    unsigned char const * const
        p_symbol_name_min,
    unsigned char const * const
        p_symbol_name_max,
    void * * const
        r_symbol)
{
    return
        appl_library_service::s_query(
            p_library,
            p_symbol_name_min,
            p_symbol_name_max,
            r_symbol);

} /* query() */

/* end-of-file: appl_library_handle.cpp */
