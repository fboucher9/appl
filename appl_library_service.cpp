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

#include <appl_library_service.h>

#include <appl_library_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_unused.h>

#include <appl_heap.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <appl_library_node.h>

#include <appl_library_mgr.h>

#if defined APPL_OS_LINUX

//
//
//
class appl_library_std_node : public appl_library
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
                    r_library);

    protected:

        appl_library_std_node();

        virtual
        ~appl_library_std_node();

        enum appl_status
            init(
                struct appl_library_descriptor const * const
                    p_library_descriptor);

    private:

        appl_library_std_node(
            class appl_library_std_node const & r);

        class appl_library_std_node &
            operator =(
                class appl_library_std_node const & r);

        static
        void
        s_new(
            void * const
                p_placement);

}; // class appl_library_std_node

//
//
//
enum appl_status
    appl_library_std_node::s_create(
        struct appl_context * const
            p_context,
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    enum appl_status
        e_status;

    class appl_library_std_node *
        p_library_std_node;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_library_std_node::s_new),
            (&
                appl_library_std_node::init),
            p_library_descriptor,
            &(
                p_library_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library) =
            p_library_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_library_std_node::appl_library_std_node() :
    appl_library()
{
}

//
//
//
appl_library_std_node::~appl_library_std_node()
{
}

//
//
//
enum appl_status
    appl_library_std_node::init(
        struct appl_library_descriptor const * const
            p_library_descriptor)
{
    appl_unused(
        p_library_descriptor);

    return
        appl_status_ok;

} // init()

//
//
//
void
appl_library_std_node::s_new(
    void * const
        p_placement)
{
    new (p_placement)
        class appl_library_std_node;

} // s_new()

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_LINUX

//
//
//
class appl_library_std_mgr : public appl_library_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                class appl_library_mgr * * const
                    r_library_mgr);

    protected:

        appl_library_std_mgr();

        virtual
        ~appl_library_std_mgr();

    private:

        appl_library_std_mgr(
            class appl_library_std_mgr const & r);

        class appl_library_std_mgr &
            operator =(
                class appl_library_std_mgr const & r);

        static
            void
            s_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

}; // class appl_library_std_mgr

//
//
//
enum appl_status
    appl_library_std_mgr::s_create(
        struct appl_context * const
            p_context,
        class appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

    class appl_library_std_mgr *
        p_library_std_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_library_std_mgr::s_new),
            &(
                p_library_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library_mgr) =
            p_library_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_library_std_mgr::appl_library_std_mgr() :
    appl_library_mgr()
{
}

//
//
//
appl_library_std_mgr::~appl_library_std_mgr()
{
}

//
//
//
void
    appl_library_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_library_std_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_library_std_mgr::v_create_node(
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

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <appl_library_w32_mgr.h>

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
enum appl_status
    appl_library_service::s_create(
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

//
//
//
enum appl_status
    appl_library_service::s_destroy(
        struct appl_library * const
            p_library)
{
    return
        p_library->destroy();

} // s_destroy()

//
//
//
struct appl_object *
    appl_library_service::s_parent(
        struct appl_library * const
            p_library)
{
    return
        p_library;

} // s_parent()

//
//
//
struct appl_object const *
    appl_library_service::s_const_parent(
        struct appl_library const * const
            p_library)
{
    return
        p_library;

} // s_const_parent()

//
//
//
enum appl_status
    appl_library_service::s_query(
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

/* end-of-file: appl_library_service.cpp */
