/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_library_handle.h>

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
                    r_symbol)
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

class appl_library_std_node : public appl_library
{
    public:

    protected:

    private:

}; // class appl_library_std_node

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
        }

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
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library)
        {
        } // v_create_node()

}; // class appl_library_std_mgr

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
    appl_object_destroy(
        p_library);

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