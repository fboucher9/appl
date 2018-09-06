
#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_pool::v_alloc(
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        r_buf);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_alloc()

//
//
//
enum appl_status
    appl_pool::v_free(
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        p_buf);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_free()

//
//
//
appl_pool::appl_pool() :
    appl_object()
{
}

//
//
//
appl_pool::~appl_pool()
{
}

/* end-of-file: appl_pool.cpp */
