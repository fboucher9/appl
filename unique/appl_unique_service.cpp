
#include <appl_status.h>

#include <appl_predefines.h>

#include <unique/appl_unique_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <unique/appl_unique.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_unique_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_unique * * const
        r_unique)
{
    enum appl_status
        e_status;

    class appl_unique_mgr *
        p_unique_mgr;

    e_status =
        p_context->v_unique_mgr(
            &(
                p_unique_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_unique_mgr->v_create(
                r_unique);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_unique_service::s_destroy(
    struct appl_unique * const
        p_unique)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_unique->get_context();

    class appl_unique_mgr *
        p_unique_mgr;

    e_status =
        p_context->v_unique_mgr(
            &(
                p_unique_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_unique_mgr->v_destroy(
                p_unique);
    }

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_unique_service::s_parent(
    struct appl_unique * const
        p_unique)
{
    return
        p_unique;

} // s_parent()

//
//
//
struct appl_object const *
appl_unique_service::s_const_parent(
    struct appl_unique const * const
        p_unique)
{
    return
        p_unique;

} // s_const_parent()

//
//
//
unsigned long int
appl_unique_service::s_get(
    struct appl_unique const * const
        p_unique)
{
    return
        p_unique->f_get();

} // s_get()

/* end-of-file: appl_unique_service.cpp */
