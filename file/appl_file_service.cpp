/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <file/appl_file_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <file/appl_file_mgr.h>

#include <file/appl_file_node.h>

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_file_service::s_get_stdin(
        struct appl_context * const
            p_context,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    class appl_file_mgr *
        p_file_mgr;

    e_status =
        p_context->v_file_mgr(
            &(
                p_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_file_mgr->v_get_stdin(
                r_file);
    }

    return
        e_status;

} // s_get_stdin()

//
//
//
enum appl_status
    appl_file_service::s_get_stdout(
        struct appl_context * const
            p_context,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    class appl_file_mgr *
        p_file_mgr;

    e_status =
        p_context->v_file_mgr(
            &(
                p_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_file_mgr->v_get_stdout(
                r_file);
    }

    return
        e_status;

} // s_get_stdout()

//
//
//
enum appl_status
    appl_file_service::s_get_stderr(
        struct appl_context * const
            p_context,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    class appl_file_mgr *
        p_file_mgr;

    e_status =
        p_context->v_file_mgr(
            &(
                p_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_file_mgr->v_get_stderr(
                r_file);
    }

    return
        e_status;

} // s_get_stderr()

//
//
//
enum appl_status
    appl_file_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    class appl_file_mgr *
        p_file_mgr;

    e_status =
        p_context->v_file_mgr(
            &(
                p_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_file_mgr->v_create_node(
                p_file_descriptor,
                r_file);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_file_service::s_destroy(
    struct appl_file * const
        p_file)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_file->get_context();

    class appl_file_mgr *
        p_file_mgr;

    e_status =
        p_context->v_file_mgr(
            &(
                p_file_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_file_mgr->v_destroy_node(
                p_file);
    }

    return
        e_status;

} // s_destroy()


//
//
//
struct appl_object *
appl_file_service::s_parent(
    struct appl_file * const
        p_file)
{
    return
        p_file;

} // s_parent()

//
//
//
struct appl_object const *
appl_file_service::s_const_parent(
    struct appl_file const * const
        p_file)
{
    return
        p_file;

} // s_const_parent()

//
//
//
enum appl_status
    appl_file_service::s_read(
        struct appl_file * const
            p_file,
        unsigned char * const
            p_buf_cur,
        unsigned char * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    e_status =
        p_file->v_read(
            p_buf_cur,
            p_buf_max,
            r_count);

    return
        e_status;

} // read_buffer()

//
//
//
enum appl_status
    appl_file_service::s_write(
        struct appl_file * const
            p_file,
        unsigned char const * const
            p_buf_cur,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    e_status =
        p_file->v_write(
            p_buf_cur,
            p_buf_max,
            r_count);

    return
        e_status;

} // write_buffer()

/* end-of-file: appl_file_service.cpp */
