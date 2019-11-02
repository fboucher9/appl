
#include <appl_status.h>

#include <appl_predefines.h>

#include <unique/appl_unique_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_unique_service::s_pick(
    struct appl_context * const
        p_context,
    unsigned long int * const
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
            p_unique_mgr->v_pick(
                r_unique);
    }

    return
        e_status;

} // s_create()

/* end-of-file: appl_unique_service.cpp */
